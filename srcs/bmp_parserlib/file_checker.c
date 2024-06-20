#include "../../includes/file_checker.h"

void	check_arguments(int argc)
{
	if (argc < 2)
	{
		FAILURE("Please specify a file name");
	}
	if (argc > 3)
	{
		FAILURE("Please specify a single file");
	}
}

char *get_file_extension(char *file_name)
{
	int counter;

	while (file_name[counter] != '\x00')
	{
		counter ++;
	}
	while (file_name[counter] != '.')
	{
		if (counter == 0)
		{
			return (NULL);
		}
		counter --;
	}
	return (&file_name[counter]);
}

int	is_bmp(char *extension)
{
	return (!strcmp(extension, ".bmp"));
}

int	check_file_extension(char *extension)
{
	char	response;

	if (extension == NULL || !is_bmp(extension))
	{
		printf("Your file doesn't appears to be a .bmp\nContinue anywway? (Y/N) ");
		scanf("%c", &response);
		if (response == 'Y' || response == 'y')
		{
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

void	check_file_input(int argc, char **argv)
{
	char	*extension;

	check_arguments(argc);
	extension = get_file_extension(argv[1]);
	if (check_file_extension(extension) == 0)
	{
		return;				
	}
	else
	{
		FAILURE("Please specify a valid BMP file");
	}
}


