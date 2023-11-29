/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/29 14:39:09 by jteste           ###   ########.fr       */
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
	str = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (stock[i] != '\0')
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_get_line(char *stock)
{
	int		index;
	char	*str;

	index = 0;
	if (stock[index] == 0)
		return (NULL);
	while (stock[index] != '\0' && stock[index] != '\n')
		index++;
	str = malloc((index + 2) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
	{
		str[index] = stock[index];
		index ++;
	}
	if (stock[index] == '\n')
	{
		str[index] = '\n';
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_read_and_copy(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	read_size = 1;
	while (!(ft_strchr(str, '\n')) && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			return (NULL);
		}
		buffer[read_size] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = ft_read_and_copy(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_clear_stock(stock);
	return (line);
}
