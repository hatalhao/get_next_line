#include "get_next_line.h"

int main(void)
{
	char	*str;
	int		fd;
	
	fd = open(".macos", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free (str);
	}
	str = get_next_line(fd);
	printf("%s", str);
	system("leaks a.out");
	close(fd);
}
