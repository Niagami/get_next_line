/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niagami <niagami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:37:36 by jteste            #+#    #+#             */
/*   Updated: 2023/11/30 20:47:50 by niagami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *stock);
char	*ft_read_and_copy(int fd, char *str);
char	*ft_clear_stock(char *stock);
char	*ft_strchr(const char *str, int tofind);
char	*ft_strjoin(char *stock, char *buffer);
size_t	ft_strlen(const char *str);

#endif