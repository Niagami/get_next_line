/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:41 by jteste            #+#    #+#             */
/*   Updated: 2023/11/29 12:30:13 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;	

	i = 0;
	j = 0;
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			str[j++] = s1[i++];
		}
		i = 0;
	}
	while (s2[i] != '\0')
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int tofind)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ((char *) NULL);
	while (str[i] != '\0' && str[i] != (char)tofind)
	{
		i++;
	}
	if (str[i] == (char)tofind)
	{
		return ((char *)&str[i]);
	}
	else
		return ((char *) NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	len = count * size;
	if (size && (len / size != count))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
