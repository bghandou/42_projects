char	*ft_strlowcase(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
	return (s);
}
