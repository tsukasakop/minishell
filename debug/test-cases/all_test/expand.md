途中
# 変数展開

## ダブル
	"pwd"
	""pwd""
	echo "a    a"
	echo "$HOME"
	"echo $HOME"
	echo "42 | ls -l"
	echo "''quart''"
	echo "'"quart"'"
#### ダブルクォートを展開すると変数名になる場合
	echo $PAT"H"
```bash
	export VAR="Hello      World"
	echo $VAR
	echo "$VAR"
	echo \'$VAR\'
```
### エラー
- `"`
	→ bash: syntax error near unexpected token `"'にする


## シングル
	'"pwd"'
	echo 'pwd'
	echo ''pwd''
	echo '""quart""'
	echo '"'quart'"'
	echo 'a    a'
 	echo '$HOME'
	'echo $HOME'
	echo '42 | ls -l'
### エラー
- `'`
	→ bash: syntax error near unexpected token `''にする

## 環境変数
	$_
	$PATH
	echo $?
```bash
	export test="ls -l"
	$test
```
	echo $NOEXIST
