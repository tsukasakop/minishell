#!/usr/bin/env python3
"""
norminetteのエラーファイルと関数依存関係ツリーをマッチングするスクリプト
マッチしたエラー関数のみをインデント構造付きで出力します
"""
import os
import re
import subprocess
import sys

# 使用するコマンドを定義
CALLTREE_CMD = "./debug/scripts/call_tree_ctags.py"
NORMINETTE_CMD = "norminette src/*/*.c include/*.h | grep Error! | awk -F: '{print $1}'"
NORMINETTE_ERROR_COUNT_CMD = "norminette src/*/*.c include/*.h | grep Error | grep -v WRONG_SCOPE_COMMENT | grep -v LINE_TOO_LONG | grep -v TOO_MANY_LINES | wc -l"

def run_command(command):
    """指定されたコマンドを実行し、その出力を返す"""
    try:
        result = subprocess.run(command, shell=True, check=True,
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                               universal_newlines=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"コマンド実行エラー: {e}", file=sys.stderr)
        return ""

def get_function_name_from_file(filename):
    """ファイルパスから関数名を抽出する"""
    return os.path.splitext(os.path.basename(filename))[0]

def extract_error_files():
    """norminetteコマンドを実行し、エラー含むファイルのリストを取得する"""
    output = run_command(NORMINETTE_CMD)

    # エラーファイルのリストを抽出
    error_files = []
    for line in output.splitlines():
        if line and not line.startswith("norminette") and not line.startswith("Error!"):
            error_files.append(line.strip())

    return error_files

def get_error_count():
    """特定のエラーを除外した実質エラー数を取得する"""
    output = run_command(NORMINETTE_ERROR_COUNT_CMD)
    try:
        return int(output.strip())
    except ValueError:
        return 0

def get_function_call_tree():
    """関数依存関係ツリーを取得する"""
    output = run_command(CALLTREE_CMD)

    # "Function Call Tree:" 以降の行を抽出
    lines = output.splitlines()
    call_tree_lines = []
    start_idx = 0

    for i, line in enumerate(lines):
        if line.strip() == "Function Call Tree:":
            start_idx = i + 1
            break

    for i in range(start_idx, len(lines)):
        line = lines[i]
        if line.strip():  # 空行でなければ追加
            call_tree_lines.append(line)

    return call_tree_lines

def extract_function_from_line(line):
    """関数呼び出し木の行から関数名を抽出する"""
    match = re.match(r'^(\s*)(\w+)', line)
    if match:
        return match.group(2)  # 関数名部分
    return None

def find_matching_functions(call_tree_lines, error_functions):
    """
    エラー関数に一致する行を、重複なしで抽出する
    """
    matches = []
    seen_functions = set()

    for line in call_tree_lines:
        func_name = extract_function_from_line(line)
        if func_name and func_name in error_functions and func_name not in seen_functions:
            matches.append(line)
            seen_functions.add(func_name)

    return matches

def main():
    # 1. エラーファイルを取得し、関数名に変換
    error_files = extract_error_files()
    error_functions = {get_function_name_from_file(file) for file in error_files}

    # 2. 関数呼び出し木を取得
    call_tree_lines = get_function_call_tree()

    # 3. エラー関数とマッチする行を抽出（重複なし）
    matching_lines = find_matching_functions(call_tree_lines, error_functions)

    # 4. マッチした行を表示
    for line in matching_lines:
        print(line)

    # 5. エラー統計（オプション）
    error_count = get_error_count()
    print(f"\nnorminetteエラー数: {error_count}")

    return 0

if __name__ == "__main__":
    sys.exit(main())
