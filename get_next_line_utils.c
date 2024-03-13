/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:36 by msisto            #+#    #+#             */
/*   Updated: 2024/03/12 12:28:40 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_in_array(char *buf)
{
	int	i;

	i = 0;
	while (i != (BUFFER_SIZE + 1))
	{
		buf[i] = '\0';
		i++;
	}
}

void	ft_storageclear(char *storage)
{
	int	i;

	i = -1;
	while (storage[++i] != '\0')
	{
			storage[i] = '\0';
	}
}
