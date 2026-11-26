#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *line;

    int fd = open("fd3", O_RDONLY);
    if (fd == -1)
    {
        printf("hata\n");
        return 0;
    }
    while((line = get_next_line(fd)))
    {  
        printf("%s",line);
        free (line);
    }
    if (line == NULL)
        printf("null geldi");
    close(fd);
    return (0);
}