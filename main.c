#include "get_next_line.h"

int main(void)
{
	char	*str;
	
	int fd;
	fd = open("test.txt", O_RDWR);
	while ((str = get_next_line(fd)))
	    printf(". %s", str);
    
    // str = get_next_line(fd);
	// printf("- 1 - %s", str);
	// str = get_next_line(fd);
	// printf("- 2 - %s", str);
	// str = get_next_line(fd);
	// printf("- 3 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	// str = get_next_line(fd);
	// printf("- 4 - %s", str);
	close(fd);
}
