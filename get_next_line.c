/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:11:27 by clira-ne          #+#    #+#             */
/*   Updated: 2023/11/21 14:11:44 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

}



// criar funcao que recebe o fd
// ler o tamanho do buffer
// procurar \n

int main(void)
{
	int fd;
	int number_carac;
	char buffer[1024];
	int fd2;
	int number_carac2;
	char buffer2[1024];

	fd = open("gnl_texto.txt", O_RDONLY);
	number_carac = read(fd, buffer, 1024);
	get_next_line(fd);
	printf("%d\n", fd);
	printf ("%d\n", number_carac);
	printf ("%s\n", buffer);

	fd2 = open("gnl_texto2.txt", O_RDONLY);
	number_carac2 = read(fd2, buffer2, 1024);

	printf("%d\n", fd2);
	printf ("%d\n", number_carac2);
	printf ("%s\n", buffer2);
}
