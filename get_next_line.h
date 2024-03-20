/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:07:53 by msisto            #+#    #+#             */
/*   Updated: 2024/03/20 12:46:12 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*gnl_strjoin(char *line, char *buf);
char	*str_clear(char *buf);
char	*ft_strchr(char *str);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
void	ft_in_array(char *buf);
char	*print_out(char *ret);
char	*update_ret(char *ret);
char	*ft_output_set(char *ret, char *buf);

#endif
