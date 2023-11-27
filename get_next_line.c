/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clira-ne <clira-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:11:27 by clira-ne          #+#    #+#             */
/*   Updated: 2023/11/27 15:26:53 by clira-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//considerar a linha
char	*ft_get_line(char *str)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!str[i])
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

//considerar a linha após '\n'
char	*ft_save_next_line(char *str)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
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
	free(str);
	return (new_s);
}

char	*ft_read(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (NULL);
}



char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);

}
