/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/23 17:24:51 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ft_read_and_copy(t_list **head, int fd, int *read_len)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return;
	
	*read_len = read(fd, buffer, BUFFER_SIZE);
	buffer[*read_len] = '\0';
	
	
}

char *get_next_line(int fd)
{
	static t_list	*head;
	char			*line;
	int				read_len;
	head = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	ft_read_and_copy(&head, fd, &read_len); // read mon fichier et stocker le buffer dans ma liste
	// extraire la ligne de ma liste vers line 
	// vider la liste et recommencer
	
}