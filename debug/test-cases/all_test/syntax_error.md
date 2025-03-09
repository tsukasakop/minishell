
# シンタックスエラー
- `ls | "" | cat`
	→bash: : command not found


## bashでは入力待ち
- `|`
	→ bash: syntax error near unexpected token `|'にする
- `||`
	→ bash: syntax error near unexpected token `|'にする

- `"`
	→ bash: syntax error near unexpected token `"'にする
- `'`
	→ bash: syntax error near unexpected token `''にする
- `
	→ そのまま文字列として実行する
- `(`
	→ そのまま文字列として実行する

## bashではシンタックスエラーだが、そのまま文字列として実行する
- `aa[`
- `aa(`
- `)`
- `;`
- `&`

## bashとエラー文を少し変える
- `<`
	→ bash: syntax error near unexpected token `newline'にする
- `>`
	→ bash: syntax error near unexpected token `newline'にする
- `<<`
	→ bash: syntax error near unexpected token `newline'にする
- `>>`
	→ bash: syntax error near unexpected token `newline'にする
- `<<<`
	→ bash: syntax error near unexpected token `<'にする



## 自作shの構文エラー
1.
```sh
	#!/bin/bash

	if true
    	echo "Hello"
	fi
```
	↓エラー出力は以下
```bash
	./syntax_error.sh: line 5: syntax error near unexpected token `fi'
	./syntax_error.sh: line 5: `fi'
```
2.
```sh
	#!/bin/bash

	if true; then
    	echo "Hello"
```
↓エラー出力は以下
```bash
	./syntax_error.sh: line 5: syntax error: unexpected end of file
```
