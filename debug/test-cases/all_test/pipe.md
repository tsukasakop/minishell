# パイプ
#### - エラーなし オプションなし | あり 引数あり | なし
	ls | wc
	ls -l | wc -l
	ls | grep minishell

#### - 処理順の確認　sleepコマンド
	sleep 3 | ls
	ls | sleep 3

#### - fd管理の確認
	cat | cat | ls
	ls | cat | cat

#### - 特殊文字
	cat minishell | xxd | tail

#### - 大きなデータ量
	yes | head -n 10000000 | wc -l

#### 大量にパイプが繋がっている場合
	ls | cat | cat | .... | cat | ls


```bash
echo 42Tokyo > hoge
cat hoge | xxd | tail
```

```
export aa=Hello | echo $aa
export
```

## エラー

#### - 存在しないコマンド する + しない | しない + する | しない + しない
	notexist1 | notexist2
	notexist1 | ls
	ls | notexist2

#### - 存在しないコマンド する + 　する + しない　 | する + しない　+　する | しない　+　する + する | する + する + する
	ls | wc | notexist


#### - シンタックスエラー
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

