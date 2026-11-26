#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("file couldn't open\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n-- null returned --\n");
	line = get_next_line(fd);
	if (line == NULL)
		printf("-- call again: null (true) --\n");
	free(line);
	if (fd != 0)
		close(fd);
	return (0);
}