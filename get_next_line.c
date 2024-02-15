/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 07:36:05 by hatalhao          #+#    #+#             */
/*   Updated: 2024/02/15 07:36:06 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	my_free(char **str)
{
	free(*str);
	*str = 0;
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char *total, char **line)
{
	size_t	len;
	char	*reste;

	len = 0;
	reste = 0;
	if (total)
	{
		while (total[len] && total[len] != '\n')
			len++;
		len += (total[len] == '\n');
		if (len)
		{
			*line = ft_substr(total, 0, len);
			reste = ft_substr(total, len, ft_strlen(total) - len + 1);
		}
	}
	return (reste);
}

char	*ft_read(int fd)
{
	char	*str;
	char	*tmp;
	long	rd;

	str = 0;
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	rd = 1;
	while (rd)
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd == -1)
		{
			my_free(&str);
			break ;
		}
		tmp[rd] = '\0';
		str = ft_strjoin(str, tmp);
		if (new_line(tmp) >= 0)
			break ;
	}
	my_free(&tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*total;
	static char	*txt = 0;
	char		*line;
	char		*tmp;

	line = 0;
	tmp = 0;
	total = 0;
	if (fd < 0 || fd >= 1024 || read(fd, total, 0) == -1 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX)
	{
		my_free(&txt);
		return (NULL);
	}
	if (txt)
		total = ft_strjoin(txt, 0);
	tmp = ft_read(fd);
	if (tmp)
	{
		total = ft_strjoin(total, tmp);
		my_free(&tmp);
		txt = extract_line(total, &line);
	}
	my_free(&total);
	return (line);
}
