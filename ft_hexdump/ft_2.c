int		ft_strcmp(char *s1, char *s2)
{
	if ((!*s1 && !*s2) || (*s1 != *s2))
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}
