#ifndef DATA_PARSER_H
# define DATA_PARSER_H
# include "./data_getter.h"
# include "./general.h"
# include <string.h>
	
struct	s_parsed_header	*get_parsed_header(struct s_file_data *data_ptr);
struct	s_parsed_info	*get_parsed_info(struct s_file_data *data_ptr);
struct s_parsed_data    *get_parsed_data(struct s_file_data *data);

unsigned char	*allocate_string_data(size_t size);
unsigned int convert_to_uint32(unsigned char *data);
struct	s_parsed_header
{
	unsigned char	*signature;
};


struct	s_parsed_info
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	offset;
};


struct	s_parsed_data
{
	struct s_parsed_header	header;
	struct s_parsed_info	info;
};


#endif
