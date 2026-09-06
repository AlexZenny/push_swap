CFILES = push_swap.c\
	parser/parser_utils.c\
	parser/split_arg.c\
	parser/stack_funcs.c\
	operations/rotate_ops.c\
	operations/rev_rotate_ops.c\
	operations/swap_ops.c\
	operations/push_ops.c\
	algorithms/disorder.c\
	algorithms/sorting_selector.c\
	algorithms/tiny_sorting.c\
	algorithms/simple_sorting.c\
	algorithms/medium_sorting.c\
	algorithms/medium_sorting_utils.c\
	algorithms/complex_sorting.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_extras.c\
	general_utils.c\
	general_utils_2.c\
	init_structs.c\
	split.c\
	benchmark.c

OBJ_DIR = obj

OBJFILES = $(CFILES:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I.

NAME = push_swap
all: $(NAME) 

$(NAME) : $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all NAME clean fclean re

