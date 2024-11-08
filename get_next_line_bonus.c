/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:08:03 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/08 03:02:32 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	check_for_nl(char *buffer, int *i)
{
	*i = 0;
	if (!buffer)
	{
		*i = -1;
		return ;
	}
	while (buffer[*i])
	{
		if (buffer[*i] == '\n')
			return ;
		(*i)++;
	}
	*i = -1;
}

char	*get_line(char **buffer, int i)
{
	char	*line;
	char	*tmp;

	line = ft_substr(*buffer, 0, i + 1);
	if (!line)
		return (NULL);
	tmp = *buffer;
	if ((*buffer)[i + 1] != '\0')
		*buffer = ft_strdup((*buffer) + i + 1);
	else
		*buffer = NULL;
	free(tmp);
	return (line);
}

char	*get_buffer(int fd, char **buffer, char **buffer_1, ssize_t r_return)
{
	char	*line;
	int		i;

	check_for_nl(*buffer, &i);
	if (i != -1)
		return (get_line(buffer, i));
	while (1)
	{
		r_return = read(fd, *buffer_1, BUFFER_SIZE);
		if (r_return == -1)
			return (NULL);
		(*buffer_1)[r_return] = '\0';
		if (r_return == 0)
			break ;
		*buffer = ft_strjoin(*buffer, *buffer_1);
		if (!(*buffer))
			return (NULL);
		check_for_nl(*buffer, &i);
		if (i != -1)
			return (get_line(buffer, i));
	}
	return (line = *buffer, *buffer = NULL, line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*buffer_1;
	char		*line;
	ssize_t		r_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r_return = -1;
	buffer_1 = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer_1)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	line = get_buffer(fd, &buffer[fd], &buffer_1, r_return);
	free(buffer_1);
	return (line);
}