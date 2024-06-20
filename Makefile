PARSERLIB_SRC =	./srcs/bmp_parserlib/data_getter.c \
				./srcs/bmp_parserlib/file_checker.c\
				./srcs/bmp_parserlib/data_parser.c\
				./srcs/bmp_parserlib/image_printer.c\
				./srcs/bmp_parserlib/general.c\

PARSERLIB_OBJ = $(PARSERLIB_SRC:.c=.o)
PARSERLIB_PATH = ./includes/libbmp_parser.a
LIBS_LIST = bmp_parser

PROGRAM_NAME = bmp_ascii_printer

all: parserlib
	gcc srcs/main.c -L includes/ -l $(LIBS_LIST) -o $(PROGRAM_NAME)

clear:
	rm -f $(PARSERLIB_OBJ)
fclear: clear
	rm -f $(PARSERLIB_PATH)
	rm -f $(PROGRAM_NAME)
parserlib: $(PARSERLIB_OBJ)
	ar -rv $(PARSERLIB_PATH) $(PARSERLIB_OBJ)

%.o: %.c
	gcc -c $< -o $@ -I./includes

.PHONY: all clean fclean re
