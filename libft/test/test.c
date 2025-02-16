#include "ft_memory.h"
int main(void)
{
    int     ret;
    void    *p; 

    p = malloc(1);
    ret = ft_mmadd(p);
    p = ft_mmmalloc(1);
    p = ft_mmcalloc(1, 1); 
    ft_mmfree();
}
