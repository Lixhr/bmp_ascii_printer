#ifndef DATA_GETTER_H
# define DATA_GETTER_H
# include "general.h"
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t  get_file_size(char *file_name);
unsigned char    *allocate_file_buffer(size_t size);
struct s_file_data    *get_file_data(char *file_name);
struct s_file_data
{
	unsigned char	*data;
	size_t	size;
};

#endif
