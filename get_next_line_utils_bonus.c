/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:52:44 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/08 04:50:08 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char	*buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
		i++;
	return (i);
}

char	*ft_substr(char *buffer, int start, int end)
{
	char	*line;

	line = (char *) malloc(end + 1);
	if (!line)
		return (free(buffer), NULL);
	while (buffer[start] && start < end)
	{
		line[start] = buffer[start];
		start++;
	}
	line[start] = '\0';
	return (line);
}

char	*ft_strdup(char *buffer)
{
	char	*n_buffer;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(buffer);
	n_buffer = (char *) malloc(len + 1);
	if (!n_buffer)
		return (NULL);
	while (buffer[i])
	{
		n_buffer[i] = buffer[i];
		i++;
	}
	n_buffer[i] = '\0';
	return (n_buffer);
}

char	*ft_strjoin(char *buffer, char *buffer_1)
{
	size_t	t_len;
	char	*n_buffer;
	char	*tmp;
	char	*b_tmp;

	t_len = ft_strlen(buffer) + ft_strlen(buffer_1) + 1;
	n_buffer = (char *) malloc(t_len);
	if (!n_buffer)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	tmp = n_buffer;
	b_tmp = buffer;
	if (buffer)
		while (*b_tmp)
			*tmp++ = *b_tmp++;
	b_tmp = buffer_1;
	while (*b_tmp)
		*tmp++ = *b_tmp++;
	*tmp = '\0';
	if (buffer)
		free(buffer);
	return (n_buffer);
}
