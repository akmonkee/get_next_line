/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:36 by msisto            #+#    #+#             */
/*   Updated: 2024/03/26 11:08:17 by msisto           ###   ########.fr       */
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

char	*update_ret(char *ret)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	i = 0;
	if (ret[0] == '\0')
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	while (ret[++i] != '\0')
		k++;
	if (k == 0)
		return (NULL);
	temp = malloc(k + 1);
	if (!temp)
		return (NULL);
	i = i - k;
	k = -1;
	while (ret[i] != '\0')
	{
		temp[++k] = ret[i];
		i++;
	}
	printf("temp[0] %p\n", temp[0]);
	printf("temp[k + 2] %p\n", temp[k + 1]);
	temp[k + 1] = '\0';
	free(ret);
	return (temp);
}
