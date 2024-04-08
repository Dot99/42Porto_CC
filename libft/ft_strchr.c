#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    char chr;
    int i;
    
    i = -1;
    chr = (char *)s;
    
    while(chr[++i] != c)
    {
        if(!chr[i])
            return(NULL);
    }
    return(chr[i]);
}