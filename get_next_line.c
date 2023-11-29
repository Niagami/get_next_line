/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/29 12:35:20 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_stock(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (stock[i] != '\0')
		str[j++] = stock[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_get_line(char *stock)
{
	int		index;
	char	*str;

	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
		index++;
	str = malloc((index + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
	{
		str[index] = stock[index];
		index ++;
	}
	if (stock[index] == '\n')
	{
		str[index] = stock[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_read_and_copy(int fd, char *str)
{
	char	*buffer;
	int		read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
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
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	stock = ft_read_and_copy(fd, stock);
	if (stock == NULL)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_clear_stock(stock);
	return (line);
}
