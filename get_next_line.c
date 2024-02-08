#include "get_next_line.h"

// void one_line_no_nl()
// {

// }

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
	tmp = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return ;
	rd = 1;
	while (rd >= 0)
	{
		rd = read (fd, tmp, BUFFER_SIZE);
		//printf("--%s--", tmp);
		if (rd < 0)
		{
			free (tmp);
			*bool = 0;
			break ;
		}
		if (rd == 0)
		{
			free (tmp);
			*bool = 2;
			break ;
		}
		tmp[rd] = '\0';
		swp = ft_strjoin(*str, tmp);
		free(*str);
		*str = ft_strdup(swp); 
		free(swp);
		if (new_line(tmp) >= 0 || !rd)
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
		return (NULL);
	if (bool == 2)
	{
		line = ft_strdup(txt);
		free(txt);
		txt = NULL;
		return (line);
	}
	line = ft_substr(txt , 0, new_line(txt) + 1);
	tmp = ft_strdup(txt);
	free(txt);
	txt = ft_substr(tmp, new_line(tmp) + 1, ft_strlen(tmp) - new_line(tmp) - 1);
	//printf("2-- %s", txt);
	free (tmp);
	return (line);
}
