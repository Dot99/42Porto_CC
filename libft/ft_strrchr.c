#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char chr;

    chr = NULL;
    while(*s)
    {
        if(*s == (char)c)
            chr = (char *)s;
        s++;
    }
    return(chr);
}