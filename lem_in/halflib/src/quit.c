#include "libft.h"

static void	msg_(char *msg)
{
	if (msg == NULL)
	{
		write(2, "Memory allocation error :<\n", 27);
	}
	else
	{
		write(2, msg, ft_strlen(msg));
	}
	write(2, "\n", 1);
	write(2, "\7", 1);
}

void		exit_free(char *msg, int format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (format-- > 0)
		free(va_arg(ap, void *));
	msg_(msg);
	exit(-1);
}

void		exit_(char *msg)
{
	msg_(msg);
	exit(-1);
}

size_t		return_free(char *msg, int format, ...)
{
	va_list	ap;
	void	*ptr;

	va_start(ap, format);
	while (format-- > 0)
		if ((ptr = (va_arg(ap, void *))))
			free(ptr);
	msg_(msg);
	return (0);
}

size_t		return_(char *msg)
{
	msg_(msg);
	return (0);
}
