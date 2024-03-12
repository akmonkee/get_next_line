/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:23 by msisto            #+#    #+#             */
/*   Updated: 2024/03/11 14:15:30 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *line, char *buf, int len)
{
	int		i;
	int		c;
	char	*fstr;

	if (!buf)
		return (NULL);
	fstr = malloc(ft_strlen(line) + len + 1);
	if (!fstr)
		return (NULL);
	i = 0;
	c = 0;
	while (line && line[i])
		fstr[c++] = line[i++];
	i = 0;
	while (buf[i])
		fstr[c++] = buf[i++];
	fstr[c] = '\0';
	free(line);
	return (fstr);
}
char	*str_clear(char *buf, char *storage)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (buf[i] != '\n')
		i++;
	while (buf[++i] != '\0')
		k++;
	storage = malloc(k + 1);
	storage[k] = '\0';
	i = i - k;
	k = -1;
	while (buf[i] != '\0')
	{
		storage[++k] = buf[i];
		buf[i] = '\0';
		i++;
	}
	return(storage);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *) str);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			buf[BUFFER_SIZE + 1];
	char			*ret;
	int				len;

	ret = NULL;
	ft_in_array(buf);
	if (storage)
	{
		ret = gnl_strjoin(ret, storage, len);
		free(storage);
	}
	while((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buf, '\n') == NULL)
		{
			ret = gnl_strjoin(ret, buf, len);
		}
		else
		{
			storage = str_clear(buf, storage); //funzione che mette quello che sta dopo \n all-innizio e il resto a \0
			ret = gnl_strjoin(ret, buf, len);
			break ;
		}
	}
	// printf("storage: %s\n", storage);
	if (ret && *ret)
		return (ret);
	free(ret);
	return (NULL);
}

int main()
{
	int	i;
	int		fd;
	char	*output;
	i = -1;
	fd = open("file", O_RDONLY);
	while (++i <= 3)
	{
		output = get_next_line(fd);
		printf("%s", output);
	}
	free(output);
	close(fd);
}
