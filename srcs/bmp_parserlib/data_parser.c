#include "../../includes/data_parser.h"

unsigned char   *allocate_string_data(size_t size)
{
	unsigned char	*string_data;

	string_data = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (string_data == NULL)
	{
		free(string_data);
		return (NULL);
	}
	return (string_data);
}

unsigned int convert_to_uint32(unsigned char *data) 
{
	return ((unsigned int)data[3] << 24) | ((unsigned int)data[2] << 16) | ((unsigned int)data[1] << 8) | (unsigned int)data[0];
}

// ------

struct	s_parsed_header	*allocate_parsed_header()
{
	struct	s_parsed_header	*header;
	unsigned char   *signature;

	header = (struct s_parsed_header *)malloc(sizeof(struct s_parsed_header));
	if (header == NULL)
	{
		return (NULL);	
	}
	header->signature = allocate_string_data(3);
	if (header->signature == NULL)
	{
		free(header);
		return (NULL);
	}
	return (header);
}


struct s_parsed_header	*get_parsed_header(struct s_file_data *data_ptr)
{
	struct	s_parsed_header *header;
	unsigned char	*file_str_data;

	file_str_data = data_ptr->data; 
	header = allocate_parsed_header();	
	check_allocation_failure(header, "Failed to allocate memory for Header.");
	strncpy(header -> signature, file_str_data, 2);	
	return (header);
}

// ---------------


struct	s_parsed_info	*allocate_parsed_info()
{
	struct	s_parsed_info	*info;

	info = (struct s_parsed_info *)malloc(sizeof(struct s_parsed_info));
	if (info == NULL)
	{
		return (NULL);	
	}
	return (info);
}


struct s_parsed_info	*get_parsed_info(struct s_file_data *data_ptr)
{
	struct	s_parsed_info *info;
	unsigned char	*file_str_data;

	file_str_data = data_ptr->data; 
	info = allocate_parsed_info();	
	if (info == NULL)
	{
		return (NULL);
	}	
	info->width = convert_to_uint32(&file_str_data[18]);
	info->height = convert_to_uint32(&file_str_data[22]);
	info->offset = convert_to_uint32(&file_str_data[10]);
	return (info);
}


struct s_parsed_data	*get_parsed_data(struct s_file_data *data)
{
	struct s_parsed_data	*parsed_data;

	parsed_data = (struct s_parsed_data *) malloc(sizeof(struct s_parsed_data));
	check_allocation_failure(parsed_data, "Failed to allocate memory for parsed data."); 
	parsed_data ->header = *get_parsed_header(data);
	parsed_data ->info = *get_parsed_info(data);

	return (parsed_data);	
}
