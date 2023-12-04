/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:21:07 by clira-ne          #+#    #+#             */
/*   Updated: 2023/12/04 15:45:22 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//considerar, ler a linha
char	*ft_get_line(char *str)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_s = (char *)malloc((i + 2) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_s[i] = str[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

//considerar a linha após '\n' e armazenar espaço suficiente para após '\n'
char	*ft_rest_line(char *str)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
	{
		new_s = NULL;
		return (NULL);
	}
	new_s = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_s[j++] = str[i++];
	new_s[j] = '\0';
	return (new_s);
}

// para leitura do descritor de arquivo
void	ft_read(int fd, char **str, int *read_bytes, char **buf)
{
	char	*new_s;

	new_s = NULL;
	*read_bytes = read(fd, *buf, BUFFER_SIZE);
	if (*read_bytes == -1)
		return ;
	(*buf)[*read_bytes] = '\0';
	new_s = ft_strjoin(*str, *buf);
	free(*str);
	*str = new_s;
}

char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_read(fd, &str, &read_bytes, &buf);
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
		ft_read(fd, &str, &read_bytes, &buf);
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf_str[1024];
	char		*read_line;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0
		|| read(fd, &buf_str[fd], 0) < 0)
	{
		free(buf_str[fd]);
		buf_str[fd] = NULL;
		return (NULL);
	}
	read_line = ft_read_line(fd, buf_str[fd]);
	if (*read_line == '\0')
	{
		free(read_line);
		return (NULL);
	}
	buf_str[fd] = ft_rest_line(read_line);
	line = ft_get_line(read_line);
	if (*line == '\0' && *buf_str[fd] == 0)
		return (NULL);
	free(read_line);
	return (line);
}
