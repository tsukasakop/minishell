# minishell/debug

# Usage

- `make all`: debug用ビルドでコンパイルを行う。

- `make run`: `make all` ののちminishellを実行する。

- `make lldb [arg]`: `make all` ののちテストを実行する。以下の引数を設定することができる。

  - `引数なし`: `test-cases`ディレクトリ内のすべてのファイルについてテストを行う。ファイルに対するテストでは、ファイル内のすべての行をminishell/bashで実行したのち標準出力・標準エラー・シェル終了ステータスのそれぞれが一致するかチェックされる。

  - `ファイルパス`: 指定されたファイルが存在する場合、そのファイル単体を対象にテストが行われる。

  - `それ以外の文字列`: 単体のコマンド（パイプ含む）としてminishell/bashで実行したのち標準出力・標準エラー・シェル終了ステータスのそれぞれが一致するかチェックされる。

- `make lldb [infile]`: `make all` ののちlldbを起動する。以下の引数を設定することができる。

  - `infile`: 実行時に手入力でコマンドを入力する代わりとなるファイル。

# Example

`cat | cat | ls`をテストする

```sh
make test "cat | cat | ls"
```

`make test ./test-cases/pipe.txt`で発生したエラーをデバッグするためにlldbを起動する

```sh
make lldb ./test-cases/pipe.txt ```


