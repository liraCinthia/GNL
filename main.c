/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:16 by clira-ne          #+#    #+#             */
/*   Updated: 2023/11/23 18:30:12 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		number_carac;
	char	buffer[1024];

	fd = open("gnl_texto.txt", O_RDONLY);
	number_carac = read(fd, buffer, 1024);
	get_next_line(fd);
	close(fd);

	printf("%d\n", fd);
	printf ("%d\n", number_carac);
	printf ("%s\n", buffer);
}
