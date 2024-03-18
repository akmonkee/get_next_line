/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:23 by msisto            #+#    #+#             */
/*   Updated: 2024/03/18 14:51:33 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	free(line);
	return (fstr);
}

char	*str_clear(char *buf, char *storage)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (buf && buf[i] != '\n')
		i++;
	while (buf[++i] != '\0')
		k++;
	storage = malloc(k + 1);
	if (storage == NULL)
		return (NULL);
	storage[k] = '\0';
	i = i - k;
	k = -1;
	while (buf[++i] != '\0' && storage[++k] != '\0')
	{
		storage[k] = buf[i];
		buf[i] = '\0';
	}
	printf("buf: %s\n", &buf[0]);
	printf("storage: %s\n", storage);
	return (storage);
}

char	*ft_strchr(const char *str)
{
	int	i;

	i = -1;
	while (str && ++i <= BUFFER_SIZE)
	{
		if (str[i] == '\n')
		{
			return ("y");
		}
	}
	return (NULL);
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
		storage_cpy(storage, buf);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buf) == NULL)
		{
			ret = gnl_strjoin(ret, buf);
			ft_in_array(buf);
		}
		else
		{
			if (BUFFER_SIZE != 1)
				storage = str_clear(buf, storage);
			ret = gnl_strjoin(ret, buf);
			ft_in_array(buf);
			break ;
		}
	}
	if (&buf[0] != NULL)
	{
		if (ft_strchr(buf) == NULL)
		{
			ret = gnl_strjoin(ret, buf);
			ft_in_array(buf);
		}
		else
		{
			if (BUFFER_SIZE != 1)
				storage = str_clear(buf, storage);
			ret = gnl_strjoin(ret, buf);
			ft_in_array(buf);
		}
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
		// printf("line: %s\n", output);
		free(output);
	}
	// printf("line: %s\n", output);
	close(fd);
}
