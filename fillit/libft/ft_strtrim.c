#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*arr;
	size_t	len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(arr = (char*)malloc(sizeof(char) * ((len - i) + 1))))
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') != '\0')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (i < len)
	{
		arr[j] = s[i];
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
