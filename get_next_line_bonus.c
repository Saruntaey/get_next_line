/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:34 by stapee            #+#    #+#             */
/*   Updated: 2023/02/18 17:59:46 by stapee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*bff;
	char	*line;

	bff = malloc(BUFFER_SIZE + 1);
	if (!bff)
		return (NULL);
	line = do_get_next_line(fd, bff, BUFFER_SIZE + 1);
	free(bff);
	return (line);
}

char	*do_get_next_line(int fd, char *bff, int bff_size)
{
	int		n_read;
	int		done;
	char	*res;
	char	*res_tmp;

	res = NULL;
	done = 0;
	while (!done)
	{
		n_read = fill_line(fd, bff, bff_size, &done);
		if (n_read == -1)
			return (NULL);
		res_tmp = join_bff(res, bff, n_read);
		if (!res_tmp)
			return (NULL);
		free(res);
		res = res_tmp;
	}
	if (!ft_str_len(res))
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*join_bff(char *str, char *bff, int bff_size)
{
	char	*res;
	char	*res_tmp;

	if (!str)
		str = "";
	res_tmp = ft_str_clone_n(bff, bff_size);
	if (!res_tmp)
		return (NULL);
	res = ft_concat_str(str, res_tmp);
	free(res_tmp);
	return (res);
}

int	fill_line(int fd, char *bff, int bff_size, int *done)
{
	int	i;
	int	n_read;	

	i = 0;
	*done = 0;
	while (i < bff_size)
	{
		n_read = read(fd, &bff[i], 1);
		if (n_read == -1)
			return (-1);
		i += n_read;
		if (n_read == 0 || bff[i -1] == '\n')
		{
			*done = 1;
			break ;
		}
	}
	return (i);
}
