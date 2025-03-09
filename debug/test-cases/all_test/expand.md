途中
# 変数展開

## ダブル
	"pwd"
	""pwd""
	echo "a    a"
	echo "$HOME"
### エラー
	"echo $HOME"


## シングル
	echo 'pwd'
	echo ''pwd''
	echo 'a    a'
 	echo '$HOME'
### エラー
	'echo $HOME'
	'"pwd"'

## 環境変数
	$_
	$PATH
	echo $?
```bash
	export test="ls -l"
	$test
```
