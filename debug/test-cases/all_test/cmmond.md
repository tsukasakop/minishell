# 基本
	- 空行
	- 空白
	- ""
	- ''
	- " "
	- ' '
	- "		"
	- '	 		 	'


# コマンド実行

## 正常
	- 絶対パス
		/bin/ls
		/bin/ls -l


	- 相対パス
		ls
		ls -l
		sleep


## エラー
	- 存在しないコマンド
		""
		..
		_ls
		ls -0
		aiueo

	- 存在しないコマンド(スラッシュあり)
		./bin/ls
		/aiueo
		aiueo/
		ai/ueo/

	- ディレクトリ
	./
	/tmp

	- 実行権限なし
```bash
chmod -x シェルスクリプト
./シェルスクリプト
```

	- bashと挙動を変える
		- どれもそのままの文字列でパス検索する
			%ls
			!ls
			(ls)
			;ls

	- PATHを削除して、上記全てを検証
		unset PATH
