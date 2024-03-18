/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:36 by msisto            #+#    #+#             */
/*   Updated: 2024/03/18 14:39:12 by msisto           ###   ########.fr       */
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
	while (storage[i])
	{
		buf[i] = storage[i];
		storage[i] = '\0';
		i++;
	}
}
