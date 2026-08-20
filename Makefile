CFILES = ft_listsconv.c\
	rotate_ops.c\
	rev_rotate_ops.c\
	swap.c\
	push.c\
	libft.c\
	ft_main.c\
	disorder.c\

OBJ_DIR = obj
OBJFILES = $(CFILES:%.c=$(OBJ_DIR)/%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a
AR = ar rcs 
all: $(NAME) 

$(NAME) : $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all NAME clean fclean re

