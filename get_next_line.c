/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:23 by msisto            #+#    #+#             */
/*   Updated: 2024/03/19 11:46:27 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str)
{
	int	i;

	i = -1;
	while (str && ++i <= BUFFER_SIZE)
	{
		if (str[i] == '\n')
		{
			return (&str[i]);
		}
	}
	return (NULL);
}

int	ft_strlen(const char *str)
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

char	*gnl_strjoin(char *line, char *buf)
{
	int		i;
	int		c;
	char	*fstr;

	if (!buf)
		return (NULL);
	fstr = malloc(ft_strlen(line) + ft_strlen(buf) + 1);
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
	if (line)
		free(line);
	return (fstr);
}

char	*str_clear(char *buf)
{
	int			i;
	int			k;
	char		*storage;

	i = 0;
	k = 0;
	while (&buf[i] != ft_strchr(buf))
		i++;
	while (buf[++i] != '\0')
		k++;
	storage = malloc(k + 1);
	if (storage == NULL)
		return (NULL);
	storage[k] = '\0';
	i = i - k;
	k = -1;
	while (buf[i] != '\0')
	{
		storage[++k] = buf[i];
		buf[i] = '\0';
		i++;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			buf[BUFFER_SIZE + 1];
	char			*ret;

	ret = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	ft_in_array(buf);
	if (storage)
	{
		storage_cpy(storage, buf);
		ret = ft_output_set(storage, buf);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		ret = ft_output_set(storage, buf);
	}
	if (ret && *ret)
		return (ret);
	free(ret);
	return (NULL);
}

int main()
{
	int		fd;
	char	*output;

	fd = open("file", O_RDONLY);
	while ((output = get_next_line(fd)) != NULL)
	{
		printf("line: %s", output);
		free(output);
		//sleep(3);
	}
	// printf("line: %s\n", output);
	close(fd);
}
