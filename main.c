#include "get_next_line.h"

int main(void)
{
	char	*str;
	int		fd;
	int i=0;
	
	fd = open("test.txt", O_RDONLY);
	while (i < 10)
	{
		i++;
		str = get_next_line(fd);
		printf("* %d *%s", i, str);
		free (str);
	}
	// str = get_next_line(fd);
	// printf("%s", str);
	// system("leaks a.out")
	close(fd);
}
