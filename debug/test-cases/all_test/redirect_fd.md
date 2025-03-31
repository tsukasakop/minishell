# 数字つきリダイレクト
### - 問題点
	- リダイレクト左側数字(以下、n)がINT_MAXを超えた場合、の挙動がbashと異なる
	→bashの場合、コマンドの引数として受け取られるが、現状のminishellでは"Bad file descriptor"として扱われ、かつ、オーバーフローする
	- nが0の時、fd0にリダイレクトされない
#### - 構文 cmd Num > path | cmd Num> path | cmdNum> path | cmdNum>path
	echo 42Tokyo 1 > out
	echo 42Tokyo 1> out
	echo 42Tokyo1> out
	echo 42Tokyo1>out

#### - !! pathが 数字+リダイレクト
	echo 42Tokyo 1>1>

#### - 構文nが 3~9 | 10~255 | 256 | 0埋め
	echo 42Tokyo 3> out
	echo 42Tokyo 10> out
	echo 42Tokyo 255> out
	echo 42Tokyo 256> out
	echo 42Tokyo 0001> out

#### - 構文nが 1000 | 2000 | INT_MAX | ※ INT_MAX + 1 | ※ LONG_MAX | ※ LONG_MAX + 1
	echo 42Tokyo 1000> out
	echo 42Tokyo 2000> out
	echo 42Tokyo 2147483647> out
	echo 42Tokyo 2147483648> out
	echo 42Tokyo 9223372036854775807> out
	echo 42Tokyo 9223372036854775808> out

#### - 構文nが 小数点 | 16進数 | 2進数
	echo 42Tokyo 0.01> out
	echo 42Tokyo 0x1> out
	echo 42Tokyo 0b0001> out


#### - 構文nが符号付き(- +) 符号1個 | 複数
	echo 42Tokyo -1> out
	echo 42Tokyo +1> out
	echo 42Tokyo ---1> out
	echo 42Tokyo +++1> out
	echo 42Tokyo -+-+42> out
	echo 42Tokyo +-+-42> out

#### - nが0で リダイレクトが ※> | <
	cat 0>out
	cat 0<out

#### - ※ nが　0で　| リダイレクトのみ | 標準出力のみ | 標準エラーのみ | 出力なし
	0>out
	echo Hello 0>out
	ls --invalid 0>out
	sleep 1 0>out

#### - nが　1で　| リダイレクトのみ | 標準出力のみ | 標準エラーのみ | 出力なし
	1>out
	echo Hello 1>out
	ls --invalid 1>out
	sleep 1 1>out

#### - nが　2で　| リダイレクトのみ | 標準出力のみ | 標準エラーのみ | 出力なし
	2>out
	echo Hello 2>out
	ls --invalid 2>out
	sleep 1 2>out

#### - nが　3で　| リダイレクトのみ | 標準出力のみ | 標準エラーのみ | 出力なし
	3>out
	echo Hello 3>out
	ls --invalid 3>out
	sleep 1 3>out

#### - リダイレクトが同じで、pathが 全て同じ | 1つだけ異なる | 全て異なる
	echo Hello 1>out 1>out 1>out
	echo Hello 1>out 1>out1 1>out1
	echo Hello 1>out 1>out1 1>out2

#### - リダイレクトが複数で、pathが 全て同じ | 1つだけ異なる | 全て異なる
	echo Hello 0>out 1>out 2>out
	echo Hello 0>out 1>out1 2>out1
	echo Hello 0>out 1>out1 2>out2

#### - nが　0 + 1 + 2
	echo Hello 0>out 1>out1 2>2out
	echo Hello 1>out1 2>out2 0>out
	echo Hello 2>out2 0>out 1>out1
	echo Hello 0>out 2>out2 1>out1
	echo Hello 2>out2 1>out1 0>out
	echo Hello 1>out1 0>out 2>out2

#### - nが　0 → 1 → 2 → 3 → 4 | 0 ← 1 ← 2 ← 3 ← 4
	echo Hello 0>out 1>out1 2>2out 3>3out 4>4out
	echo Hello 4>4out 3>3out 2>2out 1>out1 0>out
