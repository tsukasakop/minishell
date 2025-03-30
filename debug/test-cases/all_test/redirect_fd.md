## 数字あり
	echo Hello 1>out
	cat no_exist 2> out
	cat 0< out
	echo hello 0>out
	sleep 3 0>out
	0<out cat
	echo 42 0002>out

	echo 42 -1>out
	ls -l> out
	echo Hello1>out
	echo 42Hello>out

	sleep 3 0>out
	echo 42tokyo 1>out 2>out 3>out
	echo 42tokyo 3>out 2>out 1>out


### エラー
```bash
echo 12345678>out
ls | grep out
```
