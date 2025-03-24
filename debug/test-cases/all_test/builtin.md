
## ビルドイン
## echo
### 正常
引数ある | ない
	文字列　| 一文字
	数字 | 文字列
オプションある | ない
	オプションが複数 | 一文字
	文字列の間に亜

#### - 通常
    echo
#### - 一文字 | 文字列
	echo F
	echo HELLO
#### - 数字 | 負の値　| INT_MAX + 1 | LONG_MAX + 1
	echo 0123456789
	echo -0123456789
	echo 2147483648

#### - 複数の引数 | ３つ以上の引数 | 引数の間に複数のスペースがある
	echo HELLO WORLD
	echo HELLO WORLD 42Tokyo 
	echo HELLO          WORLD
#### - オプションあり 引数あり | なし
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
#### ※ 通常
	env
#### !! 引数あり → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa
#### !! 引数あり(複数) → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa bbbbb cccc

## export
### 正常
#### ※ 引数なし | 引数あり | 複数
	* export  → 出力される順番が違う(本来はABC順)、`declare -x `とvalueに`""`がない
	export VAR=val
	export test1=hello test2=world test3=42tokyo
#### - valueにスペースを含む | 複数のスペース
	export VAR="Hello World"
	export VAR="Hello      World"
#### - valueが数字 | 文字 | 記号
	export NUM=1234567
	export TEXT=Hello
	export TEXT=!!%%
#### - valueに変数がある + クォートなし | ダブルクォート | シングルクォート
	export WITH_VAR=$VAR
	export WITH_VAR="$VAR"
	export WITH_VAR='$VAR'
#### - valueが空
	export Empty=
#### - nameに数字が含まれる場合
	export FT42=Hello
#### - 引数が空
	export $aaa
#### - 既存の変数を変更
	export VAR=test
#### ※ nameだけ設定 → 課題要件につき、bashを挙動を変えている
	export AAA

### エラー
#### - nameが数字の場合 → `not a valid identifier`　、 exit status → 1
	export 42=val
#### - nameが数字で始まる場合 → `not a valid identifier`　、 exit status → 1
	export 42FT=val
#### - ??????
	export FT%=val
#### - 設定値が空白の場合 → `not a valid identifier`　、 exit status → 1
	export "   "
#### - 途中でエラーが起きる場合 → `not a valid identifier`　、 exit status → 1、エラー対象以外の変数は設定される
	export num=1234567 str=hello c=a 42=tokyo test=yes

## unset
#### - 引数なし
	unset
#### - = なし
	unset VAR
#### - = あり
	unset VAR=
#### - nameとvalueの組み合わせ
	unset VAR=val
#### - 存在するnameとvalueの組み合わせ
	unset aa=hello
#### - 存在するnameとvalueの組み合わせ + name= のみ + nameのみ
	unset aa=hello aa= aa
#### - 複数削除
	unset test1 test2 test3
#### - 存在しない環境変数
	unset no_exist

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
	cd .
	cd ..
	cd ../
	cd -
	cd ~
	cd /
	cd /tmp
	cd $PWD
	cd $OLDPWD
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
