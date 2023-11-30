/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:16 by clira-ne          #+#    #+#             */
/*   Updated: 2023/11/30 16:29:15 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("gnl_texto.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	// line = get_next_line(fd);
	// printf("%s\n", line);
	// free(line);
	close(fd);
	return (0);
}
