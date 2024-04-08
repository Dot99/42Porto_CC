#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int     size;

	i = 0;
	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}