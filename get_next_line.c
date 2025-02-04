/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linev2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:56:40 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/02/02 14:56:40 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char **stored)
{

}

char	*ft_read(int fd, char *stored)
{
	ssize_t	bytesread;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[bytesread] = '\0';
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, stored);
	return (line);
}
