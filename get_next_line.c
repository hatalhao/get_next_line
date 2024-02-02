

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
// void	allo_read(char **str, int fd)
{
	long	rd;
	char	*tmp;
	char	*swp;

	swp = NULL;
	tmp = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return ;
	rd = 1;
	while (rd >= 0)
	{
		rd = read (fd, tmp, BUFFER_SIZE);
		if (rd <= 0)
		{
			*str = ft_strdup(tmp);
			free (tmp);
			*bool = 0;
			break ;
		}
		tmp[rd] = '\0';
		swp = ft_strjoin(*str, tmp);
		free(*str);
		*str = ft_strdup(swp); 
		free(swp);
		if (new_line(tmp) >= 0)
			return ;
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
	//printf("1-- %s\n", txt);
	allo_read(&txt, fd, &bool);
	// allo_read(&txt, fd);
	if (bool == 0)
		line = ft_strdup(txt);
	line = ft_substr(txt , 0, new_line(txt) + 1);
	tmp = ft_strdup(txt);
	free(txt);
	txt = ft_substr(tmp, new_line(tmp) + 1, ft_strlen(tmp) - new_line(tmp) - 1);
	//printf("2-- %s", txt);
	free (tmp);
	return (line);
}

int main(void)
{
	char	*str;
	
	int fd;
	fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("- 1 - %s",str);
	str = get_next_line(fd);
	printf("- 2 - %s",str);
	str = get_next_line(fd);
	printf("- 3 - %s",str);
	close(fd);
}
