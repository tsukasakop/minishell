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
