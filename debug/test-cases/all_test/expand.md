途中
# 変数展開

## ダブル
	"pwd"
	""pwd""
	echo "a    a"
	echo "$HOME"
	"echo $HOME"
	echo "42 | ls -l"
### エラー
- `"`
	→ bash: syntax error near unexpected token `"'にする



## シングル
	echo 'pwd'
	echo ''pwd''
	echo 'a    a'
 	echo '$HOME'
	'echo $HOME'
	'"pwd"'
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
