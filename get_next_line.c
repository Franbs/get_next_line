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

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 1);
		return (NULL);
	}
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	return (buffer);
}

int	main(int ac, char **av)
{
	return (0);
}
