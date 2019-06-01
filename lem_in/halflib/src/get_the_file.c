#include "libft.h"
#include "garbage.h"

static char	*add_one_byte(char *ret)
{
	char *tmp;

	tmp = ret;
	if (!ret)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(ret) + 2))))
		return (NULL);
	ft_bzero(ret, ft_strlen(tmp) + 2);
	ft_memcpy(ret, tmp, ft_strlen(tmp));
	free(tmp);
	return (ret);
}

char		*get_the_file(int fd)
{
	char		*ret;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];
	size_t		iter_max;

	iter_max = 0;
	ret = NULL;
	ft_bzero(buffer, BUFF_SIZE + 1);
	while (read(fd, buffer, BUFF_SIZE) != 0)
	{
		tmp = ret;
		if (!(ret = ft_strjoin(ret, buffer)))
			return (NULL);
		free(tmp);
		if (ft_memchr(buffer, '\0', BUFF_SIZE) != NULL)
			break ;
		ft_bzero(buffer, BUFF_SIZE + 1);
		if (iter_max++ > ITER_MAX)
			return (NULL);
	}
	return (add_one_byte(ret));
}
