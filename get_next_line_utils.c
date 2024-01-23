/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatalhao <hatalhao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:07:46 by hatalhao          #+#    #+#             */
/*   Updated: 2024/01/24 00:40:59 by hatalhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (dest == src)
		return (dest);
	str1 = (unsigned char *) src;
	str2 = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len;
	char	*str;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);	
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	str = (char *) malloc ((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2);
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(char const *src)
{
	size_t	i;
	char	*duplicate;

	duplicate = (char *) malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (src[i])
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	isleft;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || !len)
	{
		ss = (char *) malloc ((1) * sizeof(char));
		if (ss == NULL)
			return (NULL);
		ss[0] = '\0';
		return (ss);
	}
	isleft = ft_strlen(s + start);
	if (len > isleft)
		len = isleft;
	ss = (char *) malloc ((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	ft_memcpy(ss, s + start, len);
	ss[len] = '\0';
	return (ss);
}
