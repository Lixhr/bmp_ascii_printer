#ifndef FILE_CHECKER_H
# define FILE_CHECKER_H

# include "./general.h"
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_file_extension(char *file_name);
int	check_file_extension(char *extension);
void    check_arguments(int argc);
void	check_file_input(int argc, char **argv);

#endif
