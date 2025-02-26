# minishell/debug

## Usage

- `make all`: debug用ビルドでコンパイルを行い`minishell.debug.o`を作成する。（`./minishell.debug.o`で実行）

- `make run [infile]`: `make all` ののちminishellを実行する。

  - `infile`: minishell起動時にinfileのコマンドを実行する。

- `make bash [infile]`: minishellに似せたbashを実行する。

  - `infile`: bash起動時にinfileのコマンドを実行する。

- `make test [arg]`: `make all` ののちテストを実行する。テストの詳細についてはTestの項を参照。

- `make lldb [infile]`: `make all` ののちlldbを起動する。以下の引数を設定することができる。

  - `infile`: minishell起動時にinfileのコマンドを実行する。

- `make run-main [src-file]`: main関数としてsrc-fileをコンパイルして実行する。（指定のない場合はmake runを実行）

## Example

`cat | cat | ls`をテストする

```sh
make test "cat | cat | ls"
```

`make test ./test-cases/pipe.txt`でエラーが発生したので同じコマンドの入力を確認する

```sh
make test ./test-cases/pipe.txt
```

同様に同じコマンドをlldb上で試す

```sh
make lldb ./test-cases/pipe.txt
```

main関数を指定してコンパイル・実行を行う

```sh
make run-main main/test_write_heredocs.c
```

## Test

### Usage

`./test.sh [arg]` または `make test [arg]`

環境変数`MISH`にパスを指定することで任意の実行ファイルをテスト対象として指定することができる。（規定値はrepositoryルートディレクトリのminishell）

`make test`実行時はdebug用の`minishell.debug.o`から変更不可

`arg`によりテストケースを指定することができる。

  - `引数なし`: `test-cases`ディレクトリ内のすべてのファイルについてテストを行う。

  - `ファイルパス`: 指定されたファイルが存在する場合、そのファイルの中身のコマンドを対象にテストが行われる。

  - `それ以外の文字列`: 入力した文字列をコマンドとしてテストを行う。


### テスト項目

テストケースはminishell/bashそれぞれで実行されたのち、以下の各項目が一致するかチェックされる。

- 標準出力

- 標準エラー

- シェルの終了ステータス（各コマンドの終了ステータスではない点に留意）
