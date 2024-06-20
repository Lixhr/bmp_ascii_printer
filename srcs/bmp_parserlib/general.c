#include "../../includes/general.h"

void	FAILURE(char *error)
{
	fprintf(stderr, "%s\n", error);
	exit(EXIT_FAILURE);
}

void    check_allocation_failure(void *adress, char *str)
{
	if (adress == NULL)
	{
		FAILURE(str);
	}
}
