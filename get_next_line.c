#include "get_next_line.h"

//strjoin, substr, strchr, ft_strlen,

char *get_next_line(int fd)
{
    static char* buffer;
    char* temp = malloc(BUFFER_SIZE + 1);
    ssize_t n = read(fd, temp, BUFFER_SIZE);
    if(n <= 0)
        return NULL;
    temp[BUFFER_SIZE] = '\0';
    buffer = ft_strjoin(buffer,temp);
    int pos = ft_strchr(buffer, '\n'); //while will be entegrated
    if(pos == NULL)
    {
        int pos2 = ft_strchr(buffer, '\0');
        if(pos2 != NULL)
            return (NULL);
    }
    char* string = ft_substr(buffer,0,pos+1);
    char* backup = ft_substr(buffer,pos+1, ft_strlen(buffer));
    char* temp2 = buffer;
    buffer = backup;
    free(temp2);
    return(string);
}