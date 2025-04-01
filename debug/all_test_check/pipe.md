# パイプ
#### - エラーなし オプションなし | あり 引数あり | なし
	ls | wc
	ls -l | wc -l
	ls | grep minishell

#### - 処理順の確認　sleepコマンドが 先 | 後
	sleep 1 | ls
	ls | sleep 1

#### - fd管理の確認
	cat | cat | ls
	ls | cat | cat

#### - 特殊文字
	cat minishell | xxd | tail

#### - 大きなデータ量
	yes | head -n 10000000 | wc -l

```bash
echo 42Tokyo > hoge
cat hoge | xxd | tail
```

```
export aa=Hello | echo $aa
export
```

#### - 存在しないコマンド する + しない | しない + する | しない + しない
	ls | notexist2
	notexist1 | ls
	notexist1 | notexist2

#### - 存在しないコマンド する + 　する + しない　 | する + しない　+　する | しない　+　する + する | する + する + する
	ls | wc | notexist
	ls | notexist | wc
	notexist | ls | wc
	ls | wc | cat

#### - !!シンタックスエラー
- `|`
	→ bash: syntax error near unexpected token `|'にする
- `||`
	→ bash: syntax error near unexpected token `|'にする
- `| ls`
	→ bash: syntax error near unexpected token `|'
- `ls |`
	→ bash: syntax error near unexpected token `|'
- `echo  42 || cat`
	→ bash: syntax error near unexpected token `|'
- `echo  42 | | cat`
	→ bash: syntax error near unexpected token `|'
- `echo  42 | | | cat`
	→ bash: syntax error near unexpected token `|'
- `echo  42 | || cat`
	→ bash: syntax error near unexpected token `||'


#### 大量にパイプが繋がっている場合
	ls | cat | cat | .... | cat | ls
