#include "get_next_line.h"


char *do_get_next_line(int fd, char *bff, int bff_size)
{
	int n_read;
	int done;
	char *res;
	char *res_tmp;

	res = NULL;
	done = 0;
	while (!done)
	{
		n_read = fill_line(fd, bff, bff_size, &done);
		if (n_read == -1)
			return NULL;
		res_tmp = join_bff(res, bff, n_read);
		if (!res_tmp)
			return NULL;
		free(res);
		res = res_tmp;
	}
	if (!ft_str_len(res))
	{
		free(res);
		return NULL;
	}
	return res;
}

char *join_bff(char *str, char *bff, int bff_size)
{
	char *res;
	char *res_tmp;

	if (!str)
		str = "";
	res_tmp = ft_str_clone_n(bff, bff_size);
	if (!res_tmp)
		return NULL;
	res = ft_concat_str(str, res_tmp);
	free(res_tmp);
	return res;
}

int fill_line(int fd, char *bff, int bff_size, int *done)
{
	int i;
	int n_read;	

	i = 0;
	*done = 0;
	while (i < bff_size)
	{
		n_read =  read(fd, &bff[i], 1);
		if (n_read == -1)
			return -1;
		i += n_read;
		if (n_read == 0 || bff[i -1] == '\n')
		{
			*done = 1;
			break;
		}
	}
	return i;
}

char *get_next_line(int fd)
{
	char *bff;
	char *line;

	bff = malloc(BUFFER_SIZE + 1);
	if (!bff)
		return NULL;
	line = do_get_next_line(fd, bff, BUFFER_SIZE + 1);
	free(bff);
	return line;	
}

char *ft_concat_str(char *str1, char *str2)
{
	int i;
	int str1_len;
	int str2_len;
	char *res;
	
	str1_len = ft_str_len(str1);
	str2_len = ft_str_len(str2);
	res = malloc(str1_len + str2_len + 1);	
	if (!res)
		return NULL;
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

char *ft_str_clone_n(char *src, int n)
{
	char *res;
	int i;

	res = malloc(n + 1);	
	if (!res)
		return NULL;
	i = 0;
	while (i < n)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_str_clone(char *src)
{
	char *res;
	int src_len;
	int i;

	src_len = ft_str_len(src);
	res = malloc(src_len + 1);	
	if (!res)
		return NULL;
	i = 0;
	while (i < src_len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int ft_str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
