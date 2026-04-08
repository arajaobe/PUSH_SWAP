SRCS =	get_next_line_utils.c \
		get_next_line.c \

CFLAGS	= -Werror -Wextra -Wall

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

NAME = libftget.a

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
