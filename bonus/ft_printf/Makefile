SRCS =	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_double.c \
		ft_putstr.c \
		ft_putunsnbr.c \
		ft_printhexa.c \
		ft_printhexalong.c \
		ft_printpointer.c

CFLAGS	= -Werror -Wextra -Wall

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
