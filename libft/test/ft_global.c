//usr/bin/cc $0 -Iinclude -L. -lft -g -fsanitize=address -Wall -Wextra -Werror -o a.out && ./a.out; exit;

#include "ft_global.h"
#include <string.h>

void	ch_test(void)
{
	ft_set_global("mfunakos", "miyumiyu");
}

int	main(void)
{
	ft_set_global("tkondo", (void *)"kon.d.tsukasa");
	if(strcmp((const char *)ft_get_global("tkondo"), "kon.d.tsukasa"))
		return 1;
	ft_set_global("tkondo", (void *)"tequondo");
	if(strcmp((const char *)ft_get_global("tkondo"), "tequondo"))
		return 1;
	ch_test();
	if(strcmp((const char *)ft_get_global("mfunakos"), "miyumiyu"))
		return 1;
	ft_delone_global("tkondo", NULL);
	ft_delone_global("mfunakos", NULL);
}
