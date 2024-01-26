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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	allo_read(&txt, fd);
	printf("txt after allocation: %s\n", txt);
	line = ft_substr(txt , 0, new_line(txt));
	tmp = ft_strdup(txt);
	free(txt);
	txt = ft_substr(txt, new_line(tmp), ft_strlen(tmp));
	printf("txt after filled from tmp: %s\n", txt);
	return (line);
}

int main()
{
	char	*str;
	
	int fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("...%s...\n",str);
	str = get_next_line(fd);
	printf("...%s...\n",str);
	close(fd);
}
