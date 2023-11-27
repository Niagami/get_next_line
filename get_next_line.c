\/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/27 14:56:40 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_and_copy(int fd, char *line)
{
	char	*buffer;
	int		read_len;
	int		index;

	read_len = 1
	while(read_len > 0)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if(read_len == -1)
			return;
		
	}
	buffer[read_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_and_copy(fd, buffer);
	if (buffer == NULL)
		return (NULL);
}