#include "get_next_line.h"

//strjoin, substr, strchr, ft_strlen,


/*
    bazı sorunlar
    
*/
char *get_next_line(int fd)
{
    static char* buffer;
    while(ft_strnchr(buffer, '\n') == NULL)
    {
        char* temp1 = malloc(BUFFER_SIZE + 1);
        ssize_t n = read(fd, temp1, BUFFER_SIZE);
        if(n < 0)
        {
            free(temp1);
            return NULL;
        }
        else if(n == 0)
        {
            free(temp1);
            return (NULL);
        }
        temp1[n] = '\0';
        char* old_buffer = ft_strdup(buffer);
        buffer = ft_strjoin(old_buffer, temp1);
        free(old_buffer);
        free(temp1);
    }
    int pos = ft_strnchr(buffer, '\n');
    char* string = ft_substr(buffer,0,pos+1);
    char* backup = ft_substr(buffer,pos+1, ft_strlen(buffer));
    buffer = ft_strdup(backup);
    free(backup);
    return(string);
}