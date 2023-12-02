#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <fcntl.h> //
# include <stdio.h>
# include <unistd.h> //
# include <stdlib.h> //

char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_rest_line(char *str);
char	*ft_read_line(int fd, char *str);
void	ft_read(int fd, char **str, int *read_bytes, char **buf);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
