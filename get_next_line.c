#include "get_next_line.h"

char    *read_control(ssize_t n, char *temp1, char **buffer)
{
    if(n < 0)
    {
        free(temp1);
        free(*buffer);
        *buffer = NULL;
        return NULL;
    }
    free(temp1);
    if(*buffer != NULL && (*buffer)[0] == '\0')
    {
        free(*buffer);
        *buffer = NULL;
        return NULL;
    }
    else if(*buffer != NULL)
    {
        char *old_buffer = *buffer;
        *buffer = NULL;
        return(old_buffer);
    }
    return (NULL);  
}

char    *return_line(char **buffer)
{
    char *pos = ft_strchr(*buffer, '\n');
    char *old_buffer = *buffer;
    char *line = ft_substr(*buffer,0, (pos- *buffer)+1);
    if (line == NULL)
    {
        free(*buffer);
        *buffer = NULL;
        return (NULL);
    }
    *buffer = ft_substr(*buffer, (pos-*buffer)+1, ft_strlen(*buffer)-(pos-*buffer)-1);
    if(*buffer == NULL)
    {
        free(line);
        free(old_buffer);
        return (NULL);
    }
    free(old_buffer);
    return(line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    if(fd<0 || BUFFER_SIZE <=0)
        return NULL;
    while(1)
    {
        if(ft_strchr(buffer, '\n') != NULL)
            break;
        char *temp1 = malloc(BUFFER_SIZE + 1);
        if(temp1 == NULL)
        {
            free(buffer);
            buffer = NULL;
            return (NULL);
        }
        ssize_t n = read(fd, temp1, BUFFER_SIZE);
        if (n <= 0)
            return (read_control(n, temp1, &buffer));
        temp1[n] = '\0';
        char *old_buffer = buffer;
        buffer = ft_strjoin(old_buffer, temp1);
        if (buffer == NULL)
        {
            free(temp1);
            free(old_buffer);
            return (NULL);
        }
        free(old_buffer);
        free(temp1);
    }
    return(return_line(&buffer));
}