/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:16 by clira-ne          #+#    #+#             */
/*   Updated: 2023/12/04 15:41:53 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>


int	main(void)
{
	int		fd;
	int		fd_one;
	char	*line;

	fd = open("gnl_texto.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}

	fd_one = open("arquivo_two.txt", O_RDONLY);
	if (fd_one < 0)
	{
		printf("Erro ao abrir o arquivo");
		return (1);
	}
	line = get_next_line(fd_one);
	printf("%s", line);
	while (line)
	{
		free(line);
		line = get_next_line(fd_one);
		printf("%s", line);
	}
	close(fd);
	close(fd_one);
	return (0);
}
