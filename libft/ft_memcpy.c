#include "libft.h"

void *ft_memcpy(void *src, const void *dest, size_t n)
{
    unsigned char *s;
    unsigned char *d;
    
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    
    if(!n || (!d && !s))
        return(dest);
    while(n--)
        *d++ = *s++;
    return(dest);
}