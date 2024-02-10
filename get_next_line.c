#include "get_next_line.h"

void	ft_join_update(char **holder, char **container)
{
	char	*swp;
	
	swp = NULL;
	swp = ft_strjoin(*holder, *container);
	free(*holder);
	*holder = ft_strdup(swp);
	free(swp);
}

int	new_line(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

char	*ft_example(void)
{
	char	*tmp;

	tmp = malloc (BUFFER_SIZE * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	ft_read(char **str, int fd, int *bool, char *tmp)
{
	long	rd;

	rd = 1;
	while (rd >= 0)
	{
		rd = read (fd, tmp, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(tmp);
			*bool = 0;
			if (!rd)
				*bool = 2;
			break ;
		}
		tmp[rd] = '\0';
		ft_join_update(str, &tmp);
		if (new_line(tmp) >= 0)
		{
			free (tmp);
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;
	char		*tmp;
	int			bool;

	bool = 1;
	if (fd < 0 || fd < 1024 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	ft_allo_read(&txt, fd, &bool, ft_example());
	if (bool == 0)
		
		return (NULL);
	if (bool == 2)
	{
		if (!ft_strlen(txt))
		{
			free(txt);
			return (NULL);
		}
		line = ft_strdup(txt);
		free(txt);
		txt = NULL;
		return (line);
	}
	line = ft_substr(txt, 0, new_line(txt) + 1);
	tmp = ft_strdup(txt);
	free(txt);
	txt = ft_substr(tmp, new_line(tmp) + 1, ft_strlen(tmp) - new_line(tmp) - 1);
	free (tmp);
	return (line);
}
