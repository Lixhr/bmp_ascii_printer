#include "../includes/image_printer.h"

void    print_greyscale(int rgb_value)
{
    char *greyscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~i!lI;:,    \"^`\". ";
    int greyscale_length = 67;
    int rgb_index;

    rgb_value = 765 - rgb_value;
    rgb_index = (rgb_value * (greyscale_length - 1)) / 765;
    printf("%c", greyscale[rgb_index]);
}

void	print_image(struct s_file_data *data_ptr, struct s_parsed_data *data_info)
{
    int value;
	int counter;

	counter = 0;
    for (int height = 0; height < data_info->info.height; height ++)
    {
        for (int width = 0; width < data_info->info.width; width ++)
        {
            value = 0;
            for (int bit = 0; bit < 3; bit ++)
            {
				value += data_ptr->data[data_ptr->size - counter];
                counter ++;
            }
            print_greyscale(value);
            printf(" ");
        }
        while ((counter % 4) != 0)
        {
            counter ++;
        }
        printf("\n");
    }

}
