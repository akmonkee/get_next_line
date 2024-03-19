/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:36 by msisto            #+#    #+#             */
/*   Updated: 2024/03/19 11:43:32 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_in_array(char *buf)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}

void	storage_cpy(char *storage, char *buf)
{
	int	i;

	i = 0;
	while (storage && storage[i] != '\n')
	{
		buf[i] = storage[i];
		storage[i] = '\n';
		i++;
	}
}

char	*ft_output_set(char *storage, char *buf)
{
	char	*ret;

	if (!ft_strchr(buf))
	{
		ret = gnl_strjoin(ret, buf);
		ft_in_array(buf);
	}
	else
	{
		storage = str_clear(buf);
		ret = gnl_strjoin(ret, buf);
		ft_in_array(buf);
	}
	return (ret);
}
