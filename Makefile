CFILES = ft_listsconv.c\
	rotate_ops.c\
	rev_rotate_ops.c\
	swap.c\
	push.c\
	libft.c\
	ft_main.c\
	disorder.c\


OBJFILES = $(CFILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a
AR = ar rcs 
all: $(NAME) 

$(NAME) : $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all NAME clean fclean re

