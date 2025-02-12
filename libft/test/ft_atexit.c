//usr/bin/cc $0 -L. -Iinclude -lft -o a.out && ./a.out; exit;
#include "ft_stdlib.h"
#include <stdio.h>

void echo()
{
	static int c;
	printf("%d\n", c++);
}

int main()
{
	int n = 50;
	printf("atexit limit: %d\n", FT_MAX_F_ATEXIT);
	printf("try atexit %d times.\n", n);
	for(int i=0; i<n; i++)
		ft_atexit(echo);
	ft_exit(0);
}
