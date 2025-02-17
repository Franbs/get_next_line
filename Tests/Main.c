#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Ponga un archivo.");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error abriendo el archivo");
		return (1);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("Primera linea: %s", line);
		free(line);
	}
	printf("\nLeyendo lo demas:\n");
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
