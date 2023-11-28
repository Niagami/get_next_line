/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:41 by jteste            #+#    #+#             */
/*   Updated: 2023/11/28 13:55:59 by jteste           ###   ########.fr       */
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
