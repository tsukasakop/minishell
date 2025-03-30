# expand
## クォート展開
### - 問題点
	- クォートのみで実行した際、エラー文がなぜか"Permission denied"になる→commandのテストケース側での問題と同じ
#### - クォートのみ 空白なし |　あり | 複数 ダブル & シングル
	""　→ commandのテストケースで試しているため、こちらでは無視
	" "
	""""""
	""''''""

#### - 展開するとコマンドになる ダブル & シングル
	"pwd"
	""pwd""

#### - 複数の空白含む 前 |　中間 | 後ろ |　すべて | 1文字ごと  ダブル & シングル
	echo "      aa"
	echo "bb    bb"
	echo "cc      "
	echo "    aa    bb     "
	echo "a b c d e f g"

#### - コマンド全体を囲った場合
	"echo Hello"

#### - クォート + 文字列 空白なし |　あり
	echo "Hello"World
	echo "Hello" World

#### - パイプ | リダイレクト を含む
	echo "42 | ls -l"
	echo "42 > out"

#### - 複数種類のクォート ダ→シ→シ | ダ→ダ→シ | ダ→シ→ダ &逆ver
	echo "''quart1''"
	echo ""'quart2'""
	echo "'"quart3"'"

#### - クォートの中にクォート シングル | ダ + シ | シ + シ | ダ + ダ
	echo "Hello'in'quart1"
	echo "Hello"'in'"quart2"
	echo "Hello''in''quart3"
	echo "Hello""in""quart4"

### シンタックスエラー クォート1個 | クォート2個 + 1
	"
		→ bash: syntax error near unexpected token `"'にする
	'
		→ bash: syntax error near unexpected token `''にする
	""'
	''"

## 環境変数展開
#### - 環境変数 + そのまま | ダブル | シングル
	echo "$HOME"

#### クォートを展開すると変数名になる場合 + ダブル | シングル
	echo $HOM"E"

#### - 存在しない環境変数 + そのまま | ダブル | シングル
	echo "$NOEXIST"

#### - $のみ  そのまま | ダブル | シングル
	echo $

#### - 複数の空白を含む環境変数 + そのまま | ダブル | シングル
```bash
	export VAR="Hello      World"
	echo $VAR
	echo "$VAR"
	echo \'$VAR\'
```
#### - クォートで囲まれた文字列の中に環境変数 そのまま | ダブル | シングル
	echo "Home is $HOME"
	echo "Home is "$HOME""
	echo "Home is '$HOME'"

#### - 終了ステータス →　commandテストケースの方で検証する
	echo $?
