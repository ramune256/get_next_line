/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:25:43 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/03 22:52:15 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *text)
{
	char	*result;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if(!text)
		return (NULL);
	while (text[len] != '\0' && text[len] != '\n')
		len++;
	if (text[len] == '\n')
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < text)
	{
		result[i] = text[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*update_text(char *text)
{
	char	*new_saved;
	char	*text_ptr;
	int		i;

	if(!text)
		return (NULL);
	text_ptr = text;
	while (*text != '\0' && *text != '\n')
		text++;
	if (*text == '\0')
	{
		free(text);
		return (NULL);
	}
	text++;
	new_saved = malloc(sizeof(char) * (ft_strlen(text) + 1));
	i = 0;
	while (*text)
	{
		new_saved[i] = *text;
		i++;
	}
	new_saved[i] = '\0';
	free(text_ptr);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	static char	*saved_text;
	char		*line;
	char		*buffer;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(saved_text, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (saved_text == NULL)
			saved_text = malloc(sizeof(char));
		temp = ft_strjoin(saved_text, buffer);
		free(saved_text);
		saved_text = temp;
	}
	free(buffer);
	line = extract_line(saved_text);
	saved_text = update_saved(saved_text);
	return (line);
}
