#include "get_next_line.h"
#include <string.h>

char	*join_carry(char *remain)
{
	char	*total;
	char	*next;

	next = malloc (BUFFER_SIZE);
	if (next == NULL)
		return (NULL);
	total = ft_strjoin(remain, next);
	return (total);
}

int	look_for(char *str)
{
	int len;

	len = 0;
	while (str)
	{
		if (str[len] == '\n')
		{	
			//printf("IN\n");
			printf("[%d]\n", len);
			return (len);
		}
		len++;
	}
	return (0);
}

char	*all_newl(char	*str, int fd)
{
	int	rd;
	int	len;
	int	bool;

	bool = 0;
	len = 0;
	str = malloc (BUFFER_SIZE);
	if (str == NULL)
		return (NULL);
	rd = read(fd, str, BUFFER_SIZE);
	while (str[len] && (rd > 0))
	{
		if (str[len] == '\n')
		{
			if (str[len + 1]  != '\0')
				
			bool = 1;
			str[len + 1] = '\0';
			return (str);
		}
		len++;
	}
	if (len == BUFFER_SIZE && bool == 0)
		join_carry(str);
	if (rd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (NULL);
}

char    *get_next_line(int fd)
{
	static char	*str;
	char		*contain;
	char		*tmp;

	contain = NULL;
	tmp = all_newl(contain, fd);
	//printf(">> tmp = [%s] <<\n", tmp);
	printf(">> contain = [%s] <<\n", contain);
	printf(">> str = [%s] <<\n", str);
	//free (str);
	return (tmp);
}

int main()
{
	char	*str;
	
	int fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("%s",str);
	str = get_next_line(fd);
	printf("%s",str);
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
