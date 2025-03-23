
## ビルドイン
## echo
### 正常
#### - 通常
    echo
#### - 文字列の出力
	echo HELLO
#### - 複数の引数
	echo HELLO WORLD
#### - 引数の間に複数のスペースがある
	echo a    a
#### - オプションあり(引数なし)
	echo -n
#### - オプション + 複数の引数
	echo -n HELLO
#### - オプションが複数回指定されているケース → `HELLO WORLD`
	echo -n -n -n HELLO WORLD
#### - オプションが引数の途中にある → `HELLO -n WORLD -n`
	echo -n HELLO -n WORLD -n
#### ※ オプションが連続するケース(引数なし)
	echo -nnn
#### ※ オプションが連続するケース(引数あり) → `HELLO`
	echo -nnn HELLO
#### ※ -nnn と -n の混在 → `HELLO`
	echo -nnn  -n HELLO

## env
### 正常
#### ※ 通常 → `_=`の結果が異なる
	env
#### !! 引数あり → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa
#### !! 引数あり(複数) → 課題要件につき、envの結果が出力されれば良い
	env aaaaaa bbbbb cccc

## export
### 正常
#### ※ 通常 → 出力されるじゅんばんが違う(本来はABC順)、`declare -x `とvalueに`""`がない
	export
#### - 環境変数の設定
	export VAR=val
#### - valueにスペースを含む
	export VAR="Hello World"
#### - valueが数字
	export NUM=1234567
#### - ダブルクォート + valueに複数のスペース
	export VAR="Hello      World"
#### - ダブルクォート + valueに変数がある
	export WITH_VAR="Is $VAR ."
#### - シングルクォート + valueに変数がある
	export WITH_VAR='Is $VAR .'
#### - valueが空
	export Empty=
#### - nameに数字が含まれる場合
	export FT42=Hello
#### - 複数の変数を一括で設定
	export test1=hello test2=world test3=42tokyo
#### - 引数が空
	export $aaa
#### - 既存の変数を変更
	export VAR=test
#### - nameだけ設定
	export AAA

### エラー
#### - nameが数字の場合 → `not a valid identifier`　、 exit status → 1
	export 42=val
#### - nameが数字で始まる場合 → `not a valid identifier`　、 exit status → 1
	export 42FT=val
	export FT%=val
	export $
#### - 設定値が空白の場合 → `not a valid identifier`　、 exit status → 1
	export "   "
#### - 途中でエラーが起きる場合 → `not a valid identifier`　、 exit status → 1、エラー対象以外の変数は設定される
	export num=1234567 str=hello c=a 42=tokyo test=yes

## unset
	unset
	unset VAR
	unset VAR=val
	unset test1 test2 test3

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
