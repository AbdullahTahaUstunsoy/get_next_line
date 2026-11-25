#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	join_operation(char *ptr, char const *s1, char const *s2)
{
	size_t	length1;
	size_t	length2;
	size_t	i;
	size_t	j;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	i = 0;
	while (i < length1)
	{
		ptr[i] = s1[i];
		(i)++;
	}
	j = 0;
	while (j < length2)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	length1;
	size_t	length2;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * length1 + sizeof(char)
			* length2 + 1);
	if (ptr == NULL)
		return (NULL);
	join_operation(ptr, s1, s2);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = (ft_strlen(s) + 1);
	while (len > i)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
