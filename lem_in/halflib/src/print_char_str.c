#include "libft.h"

void	print_char_str(char c, size_t nb)
{
	char	*buff;
	int		i;

	i = nb;
	if (!(buff = malloc(sizeof(char) * nb + 1)))
		exit_(NULL);
	while (i--)
		buff[i] = c;
	write(1, buff, nb);
	free(buff);
}
