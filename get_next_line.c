#include "get_next_line.h"
#include <string.h>

void	freee(char **str)
{
	free (str);
	*str = NULL;
}

char	*join_carry(char *remain)
{
	char	*total;
	char	*next;

	next = malloc (BUFFER_SIZE + 1);
	if (next == NULL)
		return (NULL);
	total = ft_strjoin(remain, next);
	freee(&next);
	return (total);
}

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

char	*ft_allocate(char *str, int fd)
{
	int	rd;
	int bool;

	str = malloc (BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	rd = 1;
	bool = -1;
	while (rd > 0 && bool < 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		//printf("**%s**\n", str);
		bool = new_line(str);
		if (bool >= 0)
			{
				//printf ("++%d++\n", bool);
				return (str);
			}
		else
			return (str);
	}
	if (rd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (str);
}

char    *get_next_line(int fd)
{
	static char	*str;
	char		*contain;
	char		*main;
	int			pos;
	int			rd;

	contain = NULL;
	contain = ft_allocate(contain, fd);
	pos = new_line (contain);
	//printf(">> container IN = [%s] <<\n", contain);
	if (str && rd > 0)
	{
		ft_memcpy (main, str, BUFFER_SIZE);
		if ((new_line(main) < 0))
			join_carry(main);
	}
	else if (pos >= 0)
	{
		main = ft_substr (contain, 0, pos);
		str = ft_substr (contain, pos, *contain - (*contain + pos));
	}
	else if (new_line (contain) < 0)
		str = join_carry(contain);
	//printf(">> main = [%s] <<\n", main);
	printf(">> str = [%s] <<\n", str);
	return (main);
}

int main()
{
	char	*str;
	//char	*str1;
	
	int fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("...%s...\n",str);
	//str1 = get_next_line(fd);
	//printf("%s",str1);
	close(fd);
}
