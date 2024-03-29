/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:15:23 by msisto            #+#    #+#             */
/*   Updated: 2024/03/27 14:45:01 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
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
	while (buf && buf[i])
		fstr[c++] = buf[i++];
	fstr[c] = '\0';
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
	if (!output)
		return (NULL);
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

char	*update_ret(char *ret)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	i = 0;
	if (!ret)
		return (NULL);
	while (ret[i] && ret[i] != '\n')
		i++;
	if (!ret[i])
	{
		free(ret);
		return (NULL);
	}
	temp = malloc(ft_strlen(ret) - i + 1);
	if (!temp)
		return (NULL);
	i++;
	k = 0;
	while (ret[i])
		temp[k++] = ret[i++];
	temp[k] = '\0';
	free(ret);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*output;
	char			buf[BUFFER_SIZE + 1];
	static char		*ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	ft_in_array(buf);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		ret = gnl_strjoin(ret, buf);
		ft_in_array(buf);
	}
	if (!ret)
		return (NULL);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	output = print_out(ret);
	ret = update_ret(ret);
	if (output && *output)
		return (output);
	free(output);
	return (NULL);
}

// int main()
// {
// 	int		fd;
// 	char	*output;

// 	fd = open("file", O_RDONLY);
// 	while ((output = get_next_line(fd)) != NULL)
// 	{
// 		printf("line: %s", output);
// 		free(output);
// 	}
// 	printf("line: %s", output);
// 	free(output);
// 	close(fd);
// }
