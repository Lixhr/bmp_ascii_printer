#ifndef IMAGE_PRINTER_H
# define IMAGE_PRINTER_H
# include <stdio.h>
# include "./data_getter.h"
# include "./data_parser.h"

void    print_greyscale(int rgb_value);
void    print_image(struct s_file_data *data_ptr, struct s_parsed_data *data_info);
#endif
