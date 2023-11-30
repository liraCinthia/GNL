/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:11:27 by clira-ne          #+#    #+#             */
/*   Updated: 2023/11/30 16:37:16 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	new_s = (char *)malloc((ft_strlen(str) - i) * sizeof(char)); //+1
	if (!new_s)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_s[j++] = str[i++];
	new_s[j] = '\0';
	// free(new_s);
	return (new_s);
}

// para leitura do descritor de arquivo
void	ft_read(int fd, char **str, int *read_bytes, char **buf)
{
	char	*new_s;

	new_s = NULL;
	*read_bytes = read(fd, *buf, BUFFER_SIZE);
	if (*read_bytes == -1)
		free(*buf);
	(*buf)[*read_bytes] = '\0';
	new_s = ft_strjoin(*str, *buf);
	free(*str);
	*str = new_s;
}

char	*ft_read_line(int fd, char *str)
{
	char	*buf;
	int		read_bytes;
	// char	*new_s;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	// read_bytes = read(fd, buf, BUFFER_SIZE);
	// if (read_bytes == -1)
	// {
	// 	free(buf);
	// 	return (NULL);
	// }
	// buf[read_bytes] = '\0';
	// new_s = ft_strjoin(str, buf);
	// free(str);
	// str = new_s;
	ft_read(fd, &str, &read_bytes, &buf);
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
		ft_read(fd, &str, &read_bytes, &buf);
		// read_bytes = read(fd, buf, BUFFER_SIZE);
		// buf[read_bytes] = '\0';
		// new_s = ft_strjoin(str, buf);
		// free(str);
		// str = new_s;
	}
	free(buf);
	return (str);
}


char	*get_next_line(int fd)
{
	static char	*buf_str;
	char		*line_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buf_str);
		buf_str = NULL;
		return (NULL);
	}
	line_read = ft_read_line(fd, buf_str);
	if (!line_read)
		return (NULL);
	buf_str = ft_next_line(line_read);
	line = ft_get_line(line_read);
	free(line_read);
	if (*line == '\0' && *buf_str == '\0')
	{
		free(line);
		free(buf_str);
		buf_str = NULL;
		return (NULL);
	}
	return (line);
}
