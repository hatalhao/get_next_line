#include "get_next_line.h"

int main(void)
{
	char	*str = 0;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	// printf("%s", str = get_next_line(fd));
	// 	free(str);
	// printf("%s", str = get_next_line(fd));
	// 	free(str);
	// printf("%s", str = get_next_line(fd));
	// 	free(str);
	// printf("%s\n", str = get_next_line(fd));
	// 	free(str);
	// while (i < 8)

	// str = get_next_line(fd);
	// printf("Line 1 == %s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("Line 2 == %s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("Line 3 == %s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("Line == %s", str);
	// free (str);
	// str = get_next_line(fd);
	// printf("Line == %s", str);
	// free (str);
	//str = get_next_line(fd);
	int i = 0;
	while( i < 2)
	{
		str = get_next_line(fd);
		printf("Line == %s", str);
		free (str);
		i++;
	}
	close(fd);
	str = get_next_line(fd);
	fd = open("file.txt", O_RDONLY);
	i = 0;
	while( i < 4)
	{
		str = get_next_line(fd);
		printf("Line == %s", str);
		free (str);
		i++;
	}
	// str = get_next_line(fd);
//	system("leaks Get_Next_line");
	// printf("Line == %s\n", str);
	// str = get_next_line(fd);
	// printf("Line == %s\n", str);
}
