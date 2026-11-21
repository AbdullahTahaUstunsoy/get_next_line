#include "get_next_line.h"

//strjoin, substr, strchr, ft_strlen,

char *get_next_line(int fd)
{
    static char* buffer;
    buffer = malloc(BUFFER_SIZE);
    ssize_t n = read(fd, buffer, BUFFER_SIZE);
    if(n <= 0)
        return NULL;
    int pos = ft_strchr(buffer, '\n');
    char* string = ft_substr(buffer,0,pos+1);
    char* backup = ft_substr(buffer,pos+1, ft_strlen(buffer));
    char* temp = buffer;
    buffer = backup;
    free(temp);
    return(string);
}