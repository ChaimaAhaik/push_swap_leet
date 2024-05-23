NAME := push_swap
BONUS := checker

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRCS := mandatory/operations1.c mandatory/operations2.c \
		mandatory/functions.c mandatory/sort_nbr.c mandatory/check_inputs.c  \
		mandatory/lib_functions.c mandatory/ft_lib2.c mandatory/ft_lists.c \
		mandatory/ft_lists2.c mandatory/ft_printf.c mandatory/main.c \

BONUS_SRC := bonus/get_next_line_bonus.c bonus/moves1_bonus.c bonus/moves2_bonus.c bonus/moves3_bonus.c \
			bonus/main_bonus.c bonus/functions_bonus.c bonus/ft_lib2_bonus.c bonus/lib_functions_bonus.c \
			bonus/ft_lists_bonus.c bonus/ft_lists2_bonus.c bonus/functions1_bonus.c bonus/check_inputs_bonus.c \
			bonus/ft_printf_bonus.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS)

mandatory/%.o : mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
