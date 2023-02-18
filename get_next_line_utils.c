/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:43:54 by stapee            #+#    #+#             */
/*   Updated: 2023/02/18 17:43:57 by stapee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concat_str(char *str1, char *str2)
{
	int		i;
	int		str1_len;
	int		str2_len;
	char	*res;

	str1_len = ft_str_len(str1);
	str2_len = ft_str_len(str2);
	res = malloc(str1_len + str2_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < str1_len)
	{
		res[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < str2_len)
	{
		res[i + str1_len] = str2[i];
		i++;
	}
	res[str1_len + str2_len] = '\0';
	return (res);
}

char	*ft_str_clone_n(char *src, int n)
{
	char	*res;
	int		i;

	res = malloc(n + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_str_clone(char *src)
{
	char	*res;
	int		src_len;
	int		i;

	src_len = ft_str_len(src);
	res = malloc(src_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
