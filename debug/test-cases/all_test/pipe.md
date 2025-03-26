途中
# パイプ
## 正常
	ls | wc
	ls | grep minishell
	ls -l | wc -l
	sleep 3 | ls
	ls | sleep 3
	echo hello world | tr 'a-z' 'A-Z'
	yes | head -n 10000000 | wc -l
	cat minishell | xxd | tail
#### 大量にパイプが繋がっている場合 + リダイレクトあり | なし
	ls | cat | cat | .... | cat | ls
	echo Hello | cat | cat | .... | cat >out
```bash
echo 42Tokyo > hoge
cat hoge | xxd | tail
```
	cat | cat | ls
```
export aa=Hello | echo $aa
export
```

## エラー

### 存在しないコマンド
	notexist | notexist2
	notexist | echo 42
	echo 42 | notexist2



### シンタックスエラー
- `echo  42 | | cat`
	→ bash: syntax error near unexpected token `|'
- `echo  42 | | | cat`
	→ bash: syntax error near unexpected token `|'
- `| ls`
	→ bash: syntax error near unexpected token `|'
- `echo  42 | || cat`
	→ bash: syntax error near unexpected token `||'

- `|`
	→ bash: syntax error near unexpected token `|'にする
- `||`
	→ bash: syntax error near unexpected token `|'にする
