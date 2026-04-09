SRCS =	bench_print.c complex_strategy.c ft_operations_push.c ft_operations_reverse_r.c ft_operations_rotate.c \
		ft_operations_swap.c ft_push_swap_utils.c ft_push_swap_utils_2.c ft_push_swap_utils_3.c ft_push_swap_utils_4.c \
		ft_push_swap_utils_5.c ft_push_swap_utils_6.c ft_push_swap_utils_7.c ft_push_swap.c ft_push_swap_utils_8.c \
		medium_strategy.c parse.c simple_sort.c simple_strategy.c strategies.c

CFLAGS		= -Werror -Wextra -Wall

OBJ_DIR = obj

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC		= cc

RM		= rm -f

NAME		= push_swap

NAME_BONUS	= checker

PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a
BONUS_DIR	= bonus


all: $(NAME)

bonus:
	$(MAKE) -C $(BONUS_DIR)
	cp $(BONUS_DIR)/$(NAME_BONUS)	.


$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(BONUS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
