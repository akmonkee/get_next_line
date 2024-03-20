/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:23 by msisto            #+#    #+#             */
/*   Updated: 2024/03/20 12:53:50 by msisto           ###   ########.fr       */
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

char	*print_out(char *ret)
{
	char	*output;
	int		i;

	i = 0;
	if (ret[0] == '\0')
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	output = malloc(i + 2);
	i = -1;
	while (ret[++i] && ret[i] != '\n')
	{
		output[i] = ret[i];
	}
	if (ret[i] == '\n')
	{
		output[i] = '\n';
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*get_next_line(int fd)
{
	char			*output;
	char			buf[BUFFER_SIZE + 1];
	static char		*ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
		ret = ft_output_set(ret, buf);
	if (!ret)
		return (NULL);
	output = print_out(ret);
	ret = update_ret(ret);
	return (output);
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
		// sleep(10000000);
	}
	// printf("line: %s\n", output);
	close(fd);
}
