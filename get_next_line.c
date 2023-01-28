#include "get_next_line.h"

char *get_next_line(int fd)
{
	char bff[BUFFER_SIZE + 1];
	int i;
	int j;
	int current_len;
	int n_read;
	char *res;
	char *res_tmp;

	i = 0;
	current_len = 0;
	res = NULL;
	while (1)
	{
		n_read += read(fd, &bff[i], 1);
		i += n_read;
		if (n_read == 0 || bff[i - 1] == '\n' )
		{
			bff[i] = '\0';
			break;
		}
		if (i == BUFFER_SIZE)
		{
			bff[i] = '\0';
			if (res == NULL)
			{
				res = ft_str_clone(bff);
				if (!res)
					return NULL;
			}
			else
			{
				res_tmp = ft_concat_str(res, bff);
				if (!res_tmp)
					return NULL;
				free(res);
				res = res_tmp;
			}
			i = 0;
			// current_len += i;

			// res_tmp = malloc(current_len + i + 1);
			// if (!res_tmp)
			// 	return NULL;
			// j = 0;
			// while (j < current_len + i)
			// {
			// 	if (res)
			// 	{
			// 		res_tmp[j] = res[j];
			// 	}	
			// 	else
			// 	{
			// 		res_tmp[j] = bff[j - current_len];
			// 	}
			// 	j++;
			// }
			// res_tmp[j] = '\0';
			// free(res);
			// res = res_tmp;
			// current_len = j;
		}
	}
	if (!res)
	{
		return ft_str_clone(bff);
	}
	res_tmp = ft_concat_str(res, bff);	
	if (!res_tmp)
		return NULL;
	free(res);	
	return res_tmp;

	//	i = 0;
	//	while (i < read_len && bff[i] != '\n')
	//	{
	//		i++;	
	//	}
	//	if (bff[i] == '\n')
	//	{
	//		i++;
	//		res = malloc(i + 1);
	//		if (!res)
	//			return NULL
	//				res[i--] = '\0';
	//		while (i >= 0)
	//		{
	//			res[i] = bff[i];
	//			i--;
	//		}
	//		return (res);
	//	}
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
