# パイプ&リダイレクト



# ビルドイン&リダイレクト


# コマンド&リダイレクト
./ 2>/tmp/file1
ls 2>/tmp/file1
ll 2>/tmp/file1
o>/tmp/file1
< /dev/stdin cat | cat | ls > /dev/stdout

# ヒアドクとエラー
#### 存在しないコマンド + 正常ヒアドク
	llll <<EOF
#### 正常ヒアドク +リダイレクトシンタックスエラー
	cat <<EOF >
#### 正常ヒアドク + パイプ + 出力リダイレクト + リダイレクトシンタックスエラー
	cat <<EOF | echo hello > out  >


# コマンド&展開
```
$HOME
```

# その他
```bash
./minishell
exit
```
norminette

## リダイレクト&展開
```bash
export VAR=
echo Hello >$VAR
```
<<"EOF"
<<'EOF'
