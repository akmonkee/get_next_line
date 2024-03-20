/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:28:36 by msisto            #+#    #+#             */
/*   Updated: 2024/03/20 14:47:44 by msisto           ###   ########.fr       */
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

char	*ft_output_set(char *ret, char *buf)
{
	ret = gnl_strjoin(ret, buf);
	ft_in_array(buf);
	return (ret);
}

char	*update_ret(char *ret)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	i = 0;
	temp = NULL;
	if (ret[0] == '\0')
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	while (ret[++i] != '\0')
		k++;
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
	temp[k + 1] = '\0';
	return (temp);
}
