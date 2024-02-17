

#include "get_next_line.h"

int	main(void)
{
	char *str = 0;
	int fd;
	int fd1;

	fd = open("test.txt", O_CREAT, O_RDWR);
	fd1 = open("file.txt", O_RDWR);
	int i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("test line == %s", str);
		free(str);
		str = get_next_line(fd1);
		printf("File Line == %s", str);
		free(str);
		i++;
	}
	close(fd);
	close(fd1);
	str = get_next_line(fd);
	printf("test **line == %s", str);
	free(str);
	fd = open("test.txt", O_CREAT, O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("test line == %s", str);
		free(str);
	}
}