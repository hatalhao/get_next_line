

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	str = s;
	a = c;
	i = 0;
	while (i < n)
		str[i++] = a;
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	str = (char *) malloc (nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, nmemb);
	return (str);
}

int	new_line(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

void	allo_read(char **str, int fd, int *bool)
{
	long	rd;
	char	*tmp;
	char	*swp;

	swp = NULL;
	tmp = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return ;
	rd = 1;
	while (rd > 0)
	{
		rd = read (fd, tmp, BUFFER_SIZE);
		if (rd <= 0)
		{
			free (tmp);
			*bool = 0;
			break ;
		}
		swp = ft_strjoin(*str, tmp);
		free(*str);
		*str = ft_strdup(swp); 
		if (new_line(tmp) >= 0)
			return ;
		free(swp);
	}
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;
	char		*tmp;
	int			bool;

	bool = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	allo_read(&txt, fd, &bool);
	if (bool == 0)
		return (txt);
	line = ft_substr(txt , 0, new_line(txt) + 1);
	tmp = ft_strdup(txt);
	free(txt);
	txt = ft_substr(tmp, new_line(tmp) + 1, ft_strlen(tmp) - new_line(tmp) - 1);
	free (tmp);
	return (line);
}

int main(void)
{
	char	*str;
	
	int fd;
	fd = open("test.txt", O_RDWR);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		//free(str);
	}
	// str = get_next_line(fd);
	// printf("-1- %s",str);
	// str = get_next_line(fd);
	// printf("-2- %s",str);
	// str = get_next_line(fd);
	// printf("-3- %s",str);
	close(fd);
}
