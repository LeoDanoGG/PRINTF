NAME        = libftprintf.a

# SRCS_START
SRCS        = ft_printf.c ft_printf_utils.c
# SRCS_END

OBJS        = $(SRCS:.c=.o)
HEADER      = 

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
