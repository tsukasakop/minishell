# 基本
### - 問題点
	- 空行、空白で実行した時の終了ステータスが異なる
	- クォートのみで実行した際、エラー文がなぜか"Permission denied"になる。終了ステータスも異なる(本来は127だが、現在は126)
	- 実行権限がない状態でコマンドを実行した時、エラー文にpathが出ない→そこまで合わせる必要性がないので現状のままにする
	- unset PATH後、クォートのみで実行した際、エラー文にbash: :の空白が出力されない→そこまで合わせる必要性がないので現状のままにする
#### - 空行  ※なし | ※ダブルクォート | ※シングルクォート

	""
	''

#### - 空白  ※なし | ダブルクォート | シングルクォート

	"    "
	'    '

# コマンド実行
## 存在するコマンド
#### - 絶対パス | 相対パス
	/bin/ls
	ls

#### - オプションあり 絶対パス | 相対パス
	/bin/ls -l
	ls -l

#### - 不正なオプション 絶対パス | 相対パス
	/bin/ls -0
	ls -0

#### - 途中で空白あり 絶対パス | 相対パス
	/bin   /ls
	l   s

#### - 引数を標準入力とするコマンド 正常な引数 | 不正な引数
	cat test-cases/all_test/txt/env.txt
	wc minishell
	cat non_existent_file.txt
	wc minishelll

#### - カレントディレクトリでの実行 コマンド名のみ | 相対パス
	cd /bin
	ls
	./ls

#### - 複数 同一 | 異なるコマンド
	ls ls ls ls
	ls date ps df


# コマンド以外
## 存在しないコマンド
#### - スラッシュなし 存在するコマンドと1文字違い | 文字列 | 数字
	lls
	aiueo
	123456789

#### - スラッシュあり 存在するコマンドと1文字違い | 文字列 | 数字 & /が最初 | 中間 | 最後
	./bin/ls
	aiueo/
	123456789/

#### - ディレクトリ名 絶対パス | 相対パス
	/tmp
	./

#### - 存在しないファイルの実行
	./non_existent_file
	/bin/non_existent_command


## 環境変数
#### - 既存 | 自作で存在するコマンド
	$USER
	export LS=ls
	$LS

#### - 環境変数 + 文字列
	export LS=ls
	$LS -l


# 自作コマンド
mkdir /tmp/minishell_cmd
cp scripts/print_hello /tmp/minishell_cmd
export PATH=/tmp/minishell_cmd:$PATH
## PATH設定前
#### - コマンドの実行 絶対パス | 相対パス
	/tmp/minishell_cmd/print_hello
	scripts/print_hello

### - ディレクトリ権限を削除 -x
	chmod -x /tmp/minishell_cmd
	/tmp/minishell_cmd/print_hello

## PATH設定後
#### - コマンドの実行 絶対パス | 相対パス | ※コマンド名のみ →　エラー出力が異なる。コマンドのpathが出力されない
	/tmp/minishell_cmd/print_hello
	scripts/print_hello
	print_hello

### - ディレクトリ権限を削除 -x
	chmod -x /tmp/minishell_cmd
	/tmp/minishell_cmd/print_hello


# unset PATH
#### - PATHを削除して、上記全てを検証
	unset PATH


# 終了ステータス
#### - 上記すべての終了ステータスを確認
	echo $?
