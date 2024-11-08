/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:47:14 by yjaafar           #+#    #+#             */
/*   Updated: 2024/11/08 02:56:49 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *buffer, int start, int end)
{
	char	*line;

	line = (char *) malloc(end + 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
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
	size_t	nb_len;

	i = 0;
	nb_len = ft_strlen(buffer);
	n_buffer = (char *) malloc(nb_len + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	t_len;
	char	*s1_tmp;
	char	*tmp;

	t_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(t_len);
	if (!res)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	tmp = res;
	s1_tmp = s1;
	if (s1)
		while (*s1_tmp)
			*tmp++ = *s1_tmp++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	if (s1)
		free(s1);
	return (res);
}
