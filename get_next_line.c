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

char	*ft_updatestored(char *stored, int i)
{
	char	*new;

	if (stored[i] == '\n')
		new = ft_strdup(&stored[i + 1]);
	else
		new = NULL;
	free(stored);
	return (new);
}

char	*ft_getline(char **stored)
{
	size_t	i;
	size_t	l;
	char	*tmp;

	i = 0;
	while ((*stored)[i] != '\n' && (*stored)[i])
		i++;
	if ((*stored)[i] == '\n')
		tmp = (char *)malloc(sizeof(char) * (i + 2));
	else
		tmp = (char *)malloc(sizeof(char) * (i + 1));
	l = 0;
	while (tmp[l] && l < i)
	{
		tmp[l] = (*stored)[l];
		l++;
	}
	if ((*stored)[i] == '\n')
	{
		tmp[l] = '\n';
		l++;
	}
	tmp[l] = '\0';
	*stored = ft_updatestored(*stored, i);
	return (tmp);
}

static char	*ft_read(int fd, char *stored)
{
	size_t	bytesread;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[bytesread] = '\0';
		stored = ft_strjoin(stored, buffer);
		if (!stored)
		{
			free(buffer);
			return (NULL);
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = ft_read(fd, stored);
	if (!stored)
		return (NULL);
	if (*stored == '\0')
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	return (ft_getline(&stored));
}
