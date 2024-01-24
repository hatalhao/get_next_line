#include "get_next_line.h"

int	new_line(char *str)
{
	int len;

	len = 0;
	while (str)
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

void    allo_read(char **str, int fd)
{
    long    rd;
    char    *tmp;

    tmp = malloc (BUFFER_SIZE + 1);
    if (!tmp)
        return ;
    rd = read (fd, tmp, BUFFER_SIZE);
    while (rd > 0)
    {
        *str = ft_strjoin(*str, tmp);
        if (new_line(tmp) >= 0)
            return ;
        rd = read (fd, tmp, BUFFER_SIZE);
    }
}

char    *get_next_line(int fd)
{
    static char *txt;
    char        *line;
    char        *tmp;

    allo_read(&txt, fd);
    line = ft_substr(txt , 0, new_line(txt));
    tmp = ft_strdup(txt);
    free(txt);
    txt = ft_substr(txt, new_line(tmp), ft_strlen(tmp));
    printf("%s\n", txt);
    return (line);
}

int main()
{
	char	*str;
	//char	*str1;
	
	int fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("...%s...\n",str);
	//str1 = get_next_line(fd);
	//printf("%s",str1);
	close(fd);
}
