//usr/bin/cc $0 -Iinclude -L. -lft -g -fsanitize=address -Wall -Wextra -Werror -o a.out && ./a.out; exit;

#include "ft_memory.h"
int main(void)
{
    int     ret;
    void    *p; 

	t_memory_manager *mm = ft_mmnew();
    p = malloc(1);
    ret = ft_mmadd(mm, p);
	(void)ret;
    p = ft_mmmalloc(mm, 1);
    p = ft_mmcalloc(mm, 1, 1); 
    ft_mmfree(mm);
/*
//*/
}
