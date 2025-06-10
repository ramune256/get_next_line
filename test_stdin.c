/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:23:36 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/10 16:41:25 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("入力: [%s]\n", line);
		free(line);
	}
	return (0);
}
