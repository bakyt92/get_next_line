NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

HEADER = get_next_line.h

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@
	@echo "DONE CORRECTLY"

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
