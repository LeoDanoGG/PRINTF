NAME        = libftprintf.a

# SRCS_START
SRCS        = ft_printf.c print_hex.c print_int.c print_ptr.c print_str.c
# SRCS_END

OBJS        = $(SRCS:.c=.o)

HEADER      = ft_printf.h

# LIBFT and the -lft flag in the $(NAME) rule
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
INCLUDES    = -I. -I$(LIBFT_DIR)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
