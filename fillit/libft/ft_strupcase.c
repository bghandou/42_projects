char	*ft_strupcase(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] > 96 && s[i] < 123)
			s[i] -= 32;
	return (s);
}
