/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:07:53 by msisto            #+#    #+#             */
/*   Updated: 2024/04/05 09:55:16 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*gnl_strjoin(char *line, char *buf);
char	*str_clear(char *buf);
char	*get_next_line(int fd);
void	ft_in_array(char *buf);
int		ft_strlen(const char *str);
char	*print_out(char *ret);
char	*update_ret(char *ret);
char	*ft_strchr(const char *s, int c);
char	*get_line(int fd, char *ret);

#endif
