/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:56:57 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/01/27 20:56:57 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	bytesread;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 1);
		return (NULL);
	}
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[bytesread] = '\0';
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	return (buffer);
}

int	main(int ac, char **av)
{
	int fd;
    char *line;

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
