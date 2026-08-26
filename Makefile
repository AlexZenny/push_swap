CFILES = ft_listsconv.c\
	rotate_ops.c\
	rev_rotate_ops.c\
	swap.c\
	push.c\
	libft.c\
	ft_main.c\
	disorder.c\
	simple_sorting.c\
	ft_debug_stacks.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_extras.c

OBJ_DIR = obj

OBJFILES = $(CFILES:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

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

