/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:27:44 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/06 13:33:15 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
    char	*line;
    int		fd;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
	{
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
