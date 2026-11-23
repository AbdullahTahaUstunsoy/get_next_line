#include "get_next_line.h"

//strjoin, substr, strchr, ft_strlen,


/*
    bazı sorular/sorunlar

    ft_strjoin'e null gidebilir mi ?

*/
char *get_next_line(int fd)
{
    static char* buffer;
    while(1)
    {
        char* temp1 = malloc(BUFFER_SIZE + 1);
        if(temp1 == NULL)
            return (NULL);
        if(ft_strchr(buffer, '\n') != NULL) // buffer'da \n varsa ekstra okumaya yapmaya gerek yok önce bufferdakini çıkartalım
        {
            free(temp1);
            break;
        }
        ssize_t n = read(fd, temp1, BUFFER_SIZE);
        if(n < 0)
        {
            free(temp1);
            return NULL;
        }
        else if(n == 0)
        {
            free(temp1);
            if(buffer != NULL && buffer[0] == '\0') //abc\n gibi bir durumda return NULL olması için.
            {
                free(buffer);
                buffer = NULL;
                return NULL;
            }
            else if(buffer != NULL)
            {
                char* string = ft_strdup(buffer);
                free(buffer);
                buffer = NULL;
                return(string);
            }
            return (NULL);
        }
        temp1[n] = '\0';
        char* old_buffer = buffer;
        buffer = ft_strjoin(old_buffer, temp1);
        free(old_buffer);
        free(temp1);
    }
    char* pos = ft_strchr(buffer, '\n');
    char* old_buffer = buffer;
    char* string = ft_substr(buffer,0, (pos-buffer)+1);
    buffer = ft_substr(buffer, (pos-buffer)+1, ft_strlen(buffer)-(pos-buffer)-1);
    free(old_buffer);
    return(string);
}