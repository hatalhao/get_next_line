#include "get_next_line.h"
#include <string.h>

int	look_for(char *str)
{
	int len;

	len = 0;
	while (str && str[len] && (str[len] != '\n'))
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}

// char	*get_split(char *str, int len)
// {
// 	char	*trim;
	
// 	trim = ft_substr(str, 0, len);
// 	return (trim);
// }

char	*all_newl(char	*str, int size, int fd)
{
	int 		rd;
	int len;

	len = 0;
	str = malloc (size);
	if (str == NULL)
		return (NULL);
	rd = read(fd, str, size);
	while (str[len] && (rd > 0))
	{
		if (str[len] == '\n')
		{
			str[len] = '\0';
			return (str);
		}
		//printf("%c", str[len]);
		len++;
	}
	if (rd <= 0 || size <= 0)
		return (NULL);
	return (NULL);
}

char    *get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	int			len;

	tmp = all_newl(str, BUFFER_SIZE, fd);
	len = look_for(str);
	//printf("%s", tmp);
	return (tmp);
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
