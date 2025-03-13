
## ビルドイン
### エラー
	/echo 42
	.echo 42
	eecho

## echo
### 正常
	echo
	echo -n
	echo hello world
	echo a    a
	echo -n hello world
	echo -n -n -n hello world
	echo -n hello world -n -n
	echo -nnn
	echo -nnn HELLO
	echo -nnn  -n HELLO
	echo -nnnnnnnnnnnnnnnnnnnnnnnnnn HELLO -n

## env
	env

## export
### 正常
	export
	export VAR=val
	export VAR="Hello      World"
	export $aaa
	export test1=hello test2=world test3=42tokyo

### エラー
	export 42=val
	export 42FT=val
	export FT%=val
	export $

## unset
	unset
	unset VAR
	unset VAR=val
	unset test1 test2 test3

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
