/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:59:18 by stapee            #+#    #+#             */
/*   Updated: 2023/02/18 17:59:21 by stapee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_concat_str(char *str1, char *str2);
int		ft_str_len(char *str);
char	*ft_str_clone(char *src);
char	*ft_str_clone_n(char *src, int n);
int		fill_line(int fd, char *bff, int bff_size, int *done);
char	*join_bff(char *str, char *bff, int bff_size);
char	*do_get_next_line(int fd, char *bff, int bff_size);

#endif
