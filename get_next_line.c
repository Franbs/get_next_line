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

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n", 2);
		return (0);
	}

	bytesread = read(fd, buffer, DEF_BUFFER - 1);
	while (bytesread > 0)
	{
		if (checkread == 0)
			return (0);
		buffer[bytesread] = '\0';
		ft_putstr(buffer, 1);
		bytesread = read(fd, buffer, DEF_BUFFER - 1);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	return (0);
}
