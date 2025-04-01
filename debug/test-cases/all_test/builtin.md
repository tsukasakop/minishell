
## ビルドイン
## echo
### 正常
#### - 引数なし
    echo
#### - 一文字 | 文字列
	echo F
	echo HELLO

#### - 数字 | 負の値　| INT_MAX + 1 | INT_MIN - 1 | LONG_MAX + 1 | LONG_MIN - 1
	echo 0123456789
	echo -0123456789
	echo 2147483648
	echo -2147483649
	echo 9223372036854775808
	echo -9223372036854775809

#### - 引数2つ | ３つ以上の引数 | 引数の間に複数のスペースがある
	echo HELLO WORLD
	echo HELLO WORLD 42Tokyo shinjuku
	echo HELLO          WORLD

#### - 制御文字 +  !!空白系(バックスラッシュに対応していないためbashと異なる) | 16進数
	echo \n \t \0
	echo 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09 0x0A 0x0B 0x0C 0x0D 0x0E 0x0F 0x7F

#### - オプション + 引数あり | なし
	echo -n HELLO
	echo -n

#### - オプションが引数の 前 | 真ん中 | 最後
	echo -n HELLO WORLD
	echo HELLO -n WORLD
	echo HELLO WORLD -n

#### - オプションが複数回指定されているケース → `HELLO WORLD`
	echo -n -n -n HELLO WORLD

#### - `-｀が連続
	echo ------n HELLO WORLD

#### !! オプションが連続で　引数あり　| 引数なし
	echo -nnnnnnnnn HELLO
	echo -nnnnnnnnn

#### !! -nnn と -n の混在 → `HELLO`
	echo -nnnnnnnnn  -n HELLO


## env
### 正常
#### !! 引数なし → bashと順番が異なる
	env
#### !! 引数あり → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa
#### !! 引数あり(複数) → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa bbbbb cccc


## export
### - 問題点
	- exportの値が変数だった場合の挙動がbashと異なる
### 正常
#### !! 引数なし | 引数あり | 複数
	export  → 出力される順番が違う(本来はABC順)、`declare -x `とvalueに`""`がない
	export VAR=val
	export test1=hello test2=world test3=42tokyo

#### - valueにスペースを含む | 複数のスペース
	export VAR="Hello World"
	export VAR="Hello      World"

#### - valueが数字 | 文字 | 記号 | 制御文字
	export NUM=1234567
	export TEXT=Hello
	export Symbol=*#%$=¥~?$+
	export BR=\n

#### - valueの変数に空白なし + クォートなし | ダブルクォート | シングルクォート
	export WITH_TEXT=$TEXT
	export WITH_TEXT="$TEXT"
	export WITH_TEXT='$TEXT'

#### - valueの変数に空白あり + ※ クォートなし | ダブルクォート | シングルクォート
	export WITH_VAR=$VAR
	export WITH_VAR="$VAR"
	export WITH_VAR='$VAR'

#### - nameにスペースを含む | 複数のスペース
	export "Hello World"=a_space
	export "Hello      World"=spaces

#### - nameに数字 | 記号 | 制御文字 を含む
	export 01234567=Hello
	export *#%$=¥~?$+=Hello
	export \n=Hello

#### - nameの変数に空白なし + クォートなし | ダブルクォート | シングルクォート
	export $TEXT=Hello
	export "$TEXT$=Hello
	export '$TEXT'=Hello

#### - nameの変数に空白あり + クォートなし | ダブルクォート | シングルクォート
	export $$VAR=Hello
	export "$VAR"=Hello
	export '$VAR'=Hello

#### - 引数の 変数展開が空 | クォート展開が空 |
	export $aaa
	export "   "

#### - nameが空 | valueが空
	export =Hello
	export Empty=

#### !! nameだけ設定 → 課題要件につき、bashを挙動を変えている
	export AAA

#### - 途中でエラーが起きる場合 → `not a valid identifier`　、 exit status → 1、エラー対象以外の変数は設定される
	export num=1234567 str=hello c=a 42=tokyo test=yes



## unset
#### - 引数なし
	unset

#### - `=` あり | `=` なし
	unset VAR=
	unset VAR

#### - 存在するname | 存在しないname |　既存のname
	unset VAR
	unset no_exist
	unset HOME

#### - 存在するnameとvalue | 存在するnameと存在しないvalue | 存在しないnameと存在するvalue | 存在しないnameと存在しないvalue
	unset VAR=test
	unset VAR=aaa
	unset noexist=test
	unset noexist=nono

#### - 複数削除
	unset test1 test2 test3

#### - 存在するnameとvalueの組み合わせ + name= のみ + nameのみ
	unset test1=hello test2= test3

#### - 変数展開後、nameが 1個 | 2個
	export cc=aa
	unset $cc
	export cc="aa bb"
	unset $cc

#### !! 読み込み専用の変数 → ビルドインコマンドであるreadonlyでしか、設定・一覧の表示ができず、minishell内では実質扱えないので、bashと挙動を変える
	unset UID



## pwd
### - 問題点
	カレントディレクトリの実行権限がない時に、pwdが表示されない
### 正常
#### - 引数あり | なし | 複数
	pwd /tmp
    pwd
	pwd /tmp /home

#### 移動後 0回 | 1回 | 2回 | 戻る
	cd .
	pwd
	cd ../
	pwd
	cd /home
	cd /tmp
	pwd
	cd /home
	pwd

#### - カレントディレクトリの権限削除 -r | -w | ※ -x
	pwd

#### - PWDを削除 直後 | 移動後
```bash
	unset PWD
	pwd
	cd ../
	pwd
```
#### - OLDPWDを削除 直後 | 移動後
```bash
	unset OLDPWD
	pwd
	cd ../
	pwd
```


## cd
### - 問題点
	- カレントディレクトリの実行権限がない時に、`../`で移動ができない→`.`や絶対パスでの移動はできる
	- PWD, OLDPWDをunset後、これらを使った移動ができない→環境変数の更新を行なっていないため。課題要件につき、PWDとOLDPWDの更新は対応しない。
	親ディレクトリの実行権限がない場合のエラー出力や、パスの変化が起きない
### 正常
#### - 引数あり | なし
	cd
	cd /tmp

#### - 存在する | しない
	cd /tmp
	cd 111111

#### - 引数が特殊
	cd .
	cd ..
	cd ../
	cd -
	cd ~
	cd /

#### スラッシュあり | なし + 存在する
	cd /tmp
	cd tmp

#### スラッシュあり | なし + 存在しない
	cd /aaa
	cd aaa

#### - 引数にクォート +  空白あり
	cd "/tmp"
	cd "/tmp    /home"
	cd '/tmp    /home'

#### - 引数2つ | ３つ以上の引数 | 空白ありの正しい引数
	cd /tmp /home
	cd /tmp /home ../
	cd /    tmp

#### - 引数に ダブルクォート | シングルクォート
	cd "/tmp"
	cd '/tmp'

#### - 引数が既存の変数 | HOME | PWD | OLDPWD
	cd $HOME
	cd $PWD
	cd $OLDPWD

#### - 引数が存在 | する変数 | しない変数
	cd $exist
	cd $aaaaa

#### - カレントディレクトリの権限削除 | -r | -w |  ※ -x
	# cd /tmp/hoge
	cd .
	※ cd ..
	cd /tmp/hoge
	cd hogeinhoge
	cd /tmp

#### - ※ 親ディレクトリの実行権限削除 + ./ | ../ | ../../
	mkdir /tmp/hoge/hogeinhoge/hogeinhoge2
	cd /tmp/hoge/hogeinhoge/hogeinhoge2
	chmod -x /tmp/hoge

#### - PWDを削除 直後 | 移動後 | ※ PWDで移動
```bash
	unset PWD
	cd $PWD
	cd ../
	cd $PWD
```

#### - OLDPWDを削除 直後 | 移動後 | ※ OLDPWDで移動
```bash
	unset OLDPWD
	cd $OLDPWD
	cd ../
	cd $OLDPWD
```

## ※ exit
### - 問題点
	不正な引数(不正な符号、LONG_MAX以上/LONG_MIN以下、数字以外、小数点)だった場合のエラー文が出ない→終了ステータスもことなる
#### - 引数なし
	exit

#### - 引数が整数 0 | 1 | 255 | 255以上 & 0 埋め数値
	exit 0
	exit 1
	exit 255
	exit 256
	exit 001

#### - 引数が符号付き(- +) 符号1個 | ※ 複数
	exit -0
	exit +0
	exit -42
	exit +42
	exit ---42
	exit +++42
	exit -+-+42
	exit +-+-42

#### - 引数が大きい数字 INT_MAX | IT_MIN | INT_MAX + 1 | INT_MIN - 1 | LONG_MAX | LONG_MIN | ※ LONG_MAX + 1 | LONG_MIN - 1
	exit 2147483647
	exit -2147483648
	exit 2147483648
	exit -2147483649
	exit 9223372036854775807
	exit -9223372036854775808
	exit 9223372036854775808
	exit -9223372036854775809

#### - ※ 引数が 小数点 | 16進数 | 2進数
	exit 0.00
	exit 4.20
	exit 0x2A
	exit 0b101010

#### - ※ 引数が数字以外 文字 | 文字列 | 数字+文字列
	exit w
	exit hello
	exit 42tokyo

#### - ※ 引数が複数 数字 + 数字 | 数字 + 文字列 | 文字列 + 数字 | 文字列 + 文字列
	exit 1 42
	exit 42 hello
	exit hello 42
	exit hello world

#### - クォートで 数字 | ※ 空 |※  空白
	exit "0"
	exit '1'
	exit ""
	exit ''
	exit "   "
	exit '   '

#### - 引数が変数 未定義 | 数字
	exit $aaa
	export STA=1
	exit $STA
