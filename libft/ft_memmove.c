#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *s;
    unsigned char *d;
    
    d = (unsigned char*)dest;
    s = (unsigned char*)src;
    
    if (s < d)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
        
}