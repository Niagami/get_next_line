/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/28 14:16:48 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_clear_stock(char *stock)
// {

// }

char	*ft_get_line(char *stock)
{
	int		index;
	char	*str;

	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
		index++;
	str = malloc((index + 2) * sizeof(char));
	str[index + 2] = '\0';
	str[index + 1] = '\n';
	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
	{
		str[index] = stock[index];
		index ++;
	}
	return (str);
}

char	*ft_read_and_copy(int fd, char *str)
{
	char	*buffer;
	int		read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	read_size = 1;
	while (!(ft_strchr(str, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	stock = ft_read_and_copy(fd, stock);
	if (stock == NULL)
		return (NULL);
	line = ft_get_line(stock);
	// stock = ft_clear_stock(stock);
	return (line);
}
