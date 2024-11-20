/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:30:35 by matomas           #+#    #+#             */
/*   Updated: 2024/09/11 11:36:06 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == '\0')
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_c);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

static char	*fill_linebuffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		temp = left_c;
		left_c = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_read == -1)
	{
		free(left_c);
		return (NULL);
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_linebuffer(fd, left_c, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}
