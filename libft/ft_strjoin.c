#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int size;
    int i;
    int j;
    char *newstring;
    
	size = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (size + 1));
    if(!newstring)
        return(NULL);
    i = -1;
    j = -1;
    while(s1[++i])
        newstring[i] = s1[i];
    while(s2[++j])
        newstring[i + j] = s2[j];
    newstring[i+j] = '\0';
    return(newstring);
}