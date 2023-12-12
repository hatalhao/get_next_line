#include "get_next_line.h"
#include <string.h>



char	*get_split(char *str)
{
	char	*trim;
	int		len;
	
	len = 0;
	while (str[len] && (str[len] != '\n'))
		len++;
	trim = ft_substr(str, 0, len);
	return (trim);
}

char    *get_next_line(int fd)
{
	static char	*str;
	int 		rd;

	str = malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	rd = read(fd, str, BUFFER_SIZE);
	if (rd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (str);
}

int main()
{
	static	char *str;
	int fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("%s--\n",str);
	// int i = 0;
	// int count;
	// printf("%p--\n", str);
	// while (*str)
	// 	{	
	// 		// str = get_next_line(fd);
	// 		// printf("[%s]\n", str);
	// 		// printf("%p--\n", str);
	// 		// str++;
	// 	}
	close(fd);
}
