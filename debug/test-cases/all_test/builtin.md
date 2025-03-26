
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

#### ※ オプションが連続で　引数あり　| 引数なし
	echo -nnnnnnnnn HELLO
	echo -nnnnnnnnn

#### ※ -nnn と -n の混在 → `HELLO`
	echo -nnnnnnnnn  -n HELLO

## env
### 正常
#### ※ 引数なし → bashと順番が異なる
	env
#### !! 引数あり → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa
#### !! 引数あり(複数) → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa bbbbb cccc

## export
### 正常
#### ※ 引数なし | 引数あり | 複数
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

#### ※ nameだけ設定 → 課題要件につき、bashを挙動を変えている
	export AAA

#### - 途中でエラーが起きる場合 → `not a valid identifier`　、 exit status → 1、エラー対象以外の変数は設定される
	export num=1234567 str=hello c=a 42=tokyo test=yes


## unset
#### - 引数なし
	unset
#### - `=` あり | `=` なし
	unset VAR=
	unset VAR
#### - 存在しないname
	unset no_exist
#### - 存在するnameとvalue | 存在するnameと存在しないvalue | 存在しないnameと存在するvalue | 存在しないnameと存在しないvalue
	unset VAR=test
	unset VAR=aaa
	unset noexist=test
	unset noexist=nono
#### - 複数削除 | 存在するnameとvalueの組み合わせ + name= のみ + nameのみ
	unset test1 test2 test3
	unset VAR=test VAR= VAR


## pwd
### 正常
#### - 引数なし | あり
    pwd
	pwd ./debug
#### 移動後
	cd ../
	pwd
	cd /tmp
	pwd
#### - PWDを削除した後の変数状況
```bash
	unset PWD
	echo $PWD
	env | grep PWD=
	export | grep PWD=
	cd .
	echo $PWD
	env | grep PWD=
	export | grep PWD=
```
```bash
	export aa=hello
	unset aa=
	env | grep aa=
	unset aa
	env | grep aa=
```

## cd
### 正常
#### - 引数あり | なし
	cd
	cd /tmp

#### - 引数が特殊
	cd .
	cd ..
	cd ../
	cd -
	cd ~
	cd /

#### スラッシュあり | なし
	cd /tmp
	cd tmp

#### - 引数が変数 | HOME | PWD | OLDPWD
	cd $HOME
	cd $PWD
	cd $OLDPWD

#### - 引数にクォート +  空白あり
	cd "/tmp"
	cd "/tmp    /home"
	cd '/tmp    /home'

#### - 引数2つ | ３つ以上の引数 | 引数の間に複数のスペースがある
	cd /tmp /home
	cd /tmp /home

#### 環境変数PWDの更新
```
	unset PWD
	echo $PWD
	cd .
	echo $PWD
```

### エラー
- 存在しない系
	cd 111111
```bash
	cd /
	cd ..
```
- 実行権限なくしてからcd
```bash
	mkdir hoge
	chmod 000 hoge/
	cd hoge
```
- ディレクトリにいる状態で実行権限なくしてからcd
```bash
	mkdir hoge
	chmod 777 hoge/
	cd hoge
	chmod 000 hoge/
	cd .
	cd ..
```
## pwd
	pwd
	pwd hogehoge
```bash
	cd /
	pwd aaaa
```

## exit
### 正常
	exit
	exit 2
	exit 000
	exit 255
	exit 256
	exit -1

### エラー
	exit hello
	exit 42tokyo
	exit 1 1
	exit 1 hello
