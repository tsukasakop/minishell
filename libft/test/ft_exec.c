//usr/bin/cc $0 -L. -Iinclude -lft -o a.out && ./a.out; exit;

#include <ft_stdlib.h>
#include <ft_unistd.h>
#include <ft_stdio.h>

int main(int argc, char **argv, char **envp)
{
	ft_initenv(envp);
	ft_printf("%s\n", ft_getenv("PATH"));
	ft_execvp("ls", (char *[]){"ls", "-l", NULL});
	//ft_execvp("/bin/ls", (char *[]){"ls", "echo", NULL});
	ft_printf("%d\n", access("/bin/cat", R_OK));
	ft_exit(0);
}
