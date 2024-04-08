#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *sub;
    
    i = 0;
    sub = (char *)malloc(sizeof(char) * (len + 1));
    if(!sub)
        return(NULL);
    while(s[start] && i < len)
    {
        sub[i] = s[start];
        i++;
        start++;
    }
    sub[i] = '\0';
    return(sub);
}