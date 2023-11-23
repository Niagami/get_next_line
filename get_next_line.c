/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/23 16:32:51 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ft_read_and_copy(t_list **head, int fd)
{
	char	*buffer;
	int read_len;
	
	read_len = read(fd, buffer, BUFFER_SIZE);
	
}

char *get_next_line(int fd)
{
	static t_list *head;
	
    if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	ft_read_and_copy(&head,fd);

	// read mon fichier et stocker le buffer
}