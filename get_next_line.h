#ifndef GET_NEXT_LINE.H
#define GET_NEXT_LINE.H
#define BUFFER_SIZE 42

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
void	join_operation(char *ptr, char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);


#endif