SRCS =	bonus.c \
		bonus_utils.c \
		bonus_utils_2.c \
		bonus_utils_3.c \
		bonus_utils_4.c \
		bonus_utils_5.c \
		bonus_utils_6.c \
		ft_operations_push.c \
		ft_operations_reverse_r.c \
		ft_operations_rotate.c \
		ft_operations_swap.c \

CFLAGS		= -Werror -Wextra -Wall

OBJ_DIR = obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC		= cc

RM		= rm -f

NAME		= checker

PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/libfget.a

all: $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(GET_NEXT_LINE_LIB):
	make -C $(GET_NEXT_LINE_DIR)

$(NAME): $(PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(GET_NEXT_LINE_DIR) -lftget -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(PRINTF_DIR) clean
	make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
