#include "get_next_line.h"
#include <string.h>
////ggjhghjgjhgj
// int ft_strlen(const char )
char	*ft_strdup(char const *src)
{
	size_t	i;
	char	*duplicate;
	// printf("---strdup---\n");
	duplicate = (char *) malloc ((strlen(src) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (src[i])
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char    *get_next_line(int fd)
{
	char		*str = malloc(10000);
	static int	i;
	int 		rd;

	rd = read(fd, str + i, buf)
	i = 0;
	if (str == NULL)
		return NULL;
	int buf = BUFFER_SIZE - BUFFER_SIZE + 1;
	while (rd > 0)
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
	if (rd <= 0 || BUFFER_SIZE <= 0)
		return NULL;
	return (str);
}

int main()
{
	char *str = NULL;
	int fd = open("test.txt", O_RDWR , 0664);
	int i = 0;
	int count = 10;
	while (i < count)
		{
			str = get_next_line(fd);
			printf("%s\n",str);
			i++;
		}
}