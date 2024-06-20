#include <stdio.h>
#include <stdlib.h>

#include "../includes/file_checker.h"
#include "../includes/general.h"
#include "../includes/data_getter.h"
#include "../includes/data_parser.h"
#include "../includes/image_printer.h"

int	main(int argc, char **argv)
{
	struct	s_file_data *unprocessed_data;
	struct	s_parsed_data *parsed_data;

	check_file_input(argc, argv);	
	unprocessed_data = get_file_data(argv[1]);

	parsed_data = get_parsed_data(unprocessed_data);
	print_image(unprocessed_data, parsed_data);

	return (0);
}
