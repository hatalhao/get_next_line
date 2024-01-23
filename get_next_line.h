#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

    #ifndef BUFFER_SIZE
    # define BUFFER_SIZE 42
    #endif

char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *src);
size_t  ft_strlen(char const *str);
void    *ft_memcpy(void *dest, void const *src, size_t n);


#endif