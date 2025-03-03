//usr/bin/cc $0 -L. -g -fsanitize=address -Iinclude -lft -o a.out && ./a.out; exit;

#include <ft_stdio.h>
#include <ft_stdlib.h>
int main(int argc, char *argv[], char *envp[])
{
	char **t;
	t=envp;
	ft_printf("----- envp -----\n");
	while(*t)
	{
		ft_printf("%s\n", *t);t++;
	}
	ft_initenv(envp);
	ft_printf("----- PATH from ft_getenv -----\n");
	ft_printf("%s\n", ft_getenv("PATH"));
	t = ft_getenvp();
	ft_printf("----- ft_getenvp -----\n");
	while(t && *t)
	{
		ft_printf("%s\n", *t);
		t++;
	}
	ft_exit(0);
}
