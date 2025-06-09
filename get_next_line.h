/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:29:17 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/09 18:20:35 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t size);

char	*free_and_null(char *text, char *buffer);
char	*extract_line(char *text);
char	*update_saved(char *text);
char	*add_text(int fd, char *saved_text);
char	*get_next_line(int fd);

#endif
