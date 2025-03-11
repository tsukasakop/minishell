# リダイレクト
## 構文
	echo Hello > out
	echo Hello >out
	echo Hello >out
	echo Hello>out

- バイナリを読み込む
	< minishell cat | xxd | tail
	< infile cat | xxd | tail
## > 出力
	> out
	echo 42tokyo > out
	echo 42tokyo > 123
```bash
chmod -r out
echo 42 > out
```
```bash
chmod -x out
echo 42 > out
```
### エラー
```bash
chmod -w out
echo 42 > out
```


## < 入力
	cat < in
```bash
	echo 42Tokyo > in
	chmod -x in
	cat < in
	42
```
```bash
	echo 42Tokyo > in
	chmod -w in
	cat < in
	42
```

### エラー
	< no_exist
```bash
	echo 42Tokyo > in
	chmod -r in
	cat < in
	bash: in: Permission denied
```

## >> 追記
	echo 42 >> out
```bash
chmod -r out
echo 42 >> out
```
```bash
chmod -x out
echo 42 >> out
```
### エラー
```bash
chmod -w out
echo 42 >> out
```
## << ヒアドク
### 正常
```bash
	<<EOF
	1
	2
	EOF
```
```bash
	cat <<EOF
	E
	O
	F
	eof
	EOF
```
```bash
	cat <<EOF <<EOF2 <<EOF3
	1
	EOF
	2
	EOF2
	3
	EOF3
```

```bash
	cat <<EOF <<EOF <<EOF
	1
	EOF
	2
	EOF
	3
	EOF
```

###  クォート(と変数展開)の正常
```bash
	cat <<"EOF"
	"EOF"
	EOF
```
```bash
	cat <<'"$VAR"'
	$VAR
	"$VAR"
```
```bash
	cat <<"'$VAR'"
	$VAR
	'$VAR'
```
```bash
	export VAR=test
	cat <<"$VAR"
	test
	"$VAR"
	$VAR
```

## 数字あり
	echo Hello 1>out
	cat no_exist 2> out
	cat 0< out
	0<out cat
	echo 42 0002>out

	echo 42 -1>out
	ls -l> out
	echo Hello1>out
	echo 42Hello>out

	echo 42tokyo 1>out 2>out 3>out
	echo 42tokyo 3>out 2>out 1>out
### エラー
```bash
echo 12345678>out
ls | grep out
```

## シンタックスエラー
- `<`
	→ bash: syntax error near unexpected token `newline'にする
- `>`
	→ bash: syntax error near unexpected token `newline'にする
- `<<`
	→ bash: syntax error near unexpected token `newline'にする
- `>>`
	→ bash: syntax error near unexpected token `newline'にする
- `<<<`
	→ bash: syntax error near unexpected token `<'にする
- `>>>`
	→ bash: syntax error near unexpected token `>'にする

- echo test >| out
	→ bash: syntax error near unexpected token `newline'にする
- cat << <<EOF

```bash
bash-5.1$ cat <<EOF <<
1
EOF
#→ls /tmp | grep heredoc_ | wc -lで、tmpにヒアドクのファイルがないか確認
```
