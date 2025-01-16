CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq

SRCS = main.c input_parse.c solve.c print_solution.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

HEADER = bsq.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Obeject files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed"

re: fclean all

.PHONY: all clean fclean re