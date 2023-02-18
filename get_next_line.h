#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 4096
# endif

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char *get_next_line(int fd);
char *ft_concat_str(char *str1, char *str2);
int ft_str_len(char *str);
char *ft_str_clone(char *src);
char *ft_str_clone_n(char *src, int n);
int fill_line(int fd, char *bff, int bff_size, int *done);
char *join_bff(char *str, char *bff, int bff_size);

#endif
