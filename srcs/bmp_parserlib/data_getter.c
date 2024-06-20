#include "../../includes/data_getter.h"
#include "../../includes/general.h"

size_t	get_file_size(char	*file_name)
{
	struct stat st;

	stat(file_name, &st);
	if (!st.st_size)
	{
		FAILURE("Your file seems corrupted/ invalid");
	}
	return (st.st_size);
}

unsigned char	*allocate_file_buffer(size_t size)
{
	unsigned char	*file_pointer;
	
	file_pointer = (char *) malloc(size +1);
	check_allocation_failure(file_pointer, "Failed to allocate buffer for your file.");
	return (file_pointer);
}

struct s_file_data	*allocate_file_data(size_t data_size)
{
	struct	s_file_data	*allocated_buffer;

	allocated_buffer = (struct s_file_data *)malloc(sizeof(struct s_file_data)); 
	allocated_buffer->data = allocate_file_buffer(data_size);

	if (!allocated_buffer)
	{
		free(allocated_buffer);
		return (NULL);
	}
	
	return (allocated_buffer);
}

struct s_file_data	*get_file_data(char *file_name)
{
	struct	s_file_data *data_ptr = NULL;
	int	file_descriptor;
    ssize_t bytes_read;
	size_t	file_size;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		close(file_descriptor);
		FAILURE("Your file doesn't exists");
	}
	file_size = get_file_size(file_name);

	data_ptr = allocate_file_data(file_size);
	check_allocation_failure(data_ptr, "Failed to allocate memory.");

	data_ptr->size = file_size;
	bytes_read = read(file_descriptor, data_ptr->data, data_ptr->size);
    if (bytes_read < 0) 
    {
       	close(file_descriptor);
       	free(data_ptr->data);
       	FAILURE("Failed to read file.");
   	}
   	data_ptr->data[bytes_read] = '\0';

	close(file_descriptor);	

	return (data_ptr);
}
