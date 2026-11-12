NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

SRCS	= ft_printf.c $(addprefix srcs/, $(addsuffix .c, ft_putchar ft_putstr \
          ft_putnbr ft_putunbr ft_puthex ft_putptr))

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c includes/ft_printf.h
	$(CC) $(CFLAGS) -I./includes/ -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
