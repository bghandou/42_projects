#include "ft_printf.h"

int		ft_count_itoa(size_t n, int base)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_convert_itoa(size_t n, char *arr, int flag, int base)
{
	char	*board;

	board = "0123456789abcdef";
	if (flag == 1)
	{
		arr[ft_count_itoa(n, base)] = '-';
		flag = 0;
	}
	if (n / base > 0)
		ft_convert_itoa(n / base, arr + 1, flag, base);
	*arr = board[n % base];
	return (arr);
}

char	*ft_itoa_basemax(size_t n, int base)
{
	int		count;
	char	*arr;
	int		flag;

	flag = 0;
	count = 0;
	arr = 0;
	if (n == 0)
		return (arr = ft_strdup("0"));
	count = ft_count_itoa(n, base);
	if (!(arr = (char*)malloc(sizeof(char) * count + 2)))
		return (0);
	arr[count + flag] = '\0';
	arr = ft_convert_itoa(n, arr, flag, base);
	arr = ft_strrev(arr);
	return (arr);
}
