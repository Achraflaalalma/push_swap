CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
LIBFT = libft/libft.a
FTPRINTF = ft_printf/libftprintf.a
HEADER = push_swap.h

SRCS =	main.c handle_args.c linked_list.c utils.c utils2.c turk_sort.c handle_errors.c handle_stack.c utils3.c turk_algo.c
BSRCS = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c linked_list.c checker_utils1_bonus.c \
		handle_args.c utils3.c handle_errors.c checker_bonus.c checker_utils_bonus.c handle_stack.c checker_errors.c

OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)
NAME = push_swap 

all: start $(NAME)
	@echo "Push_swap Good"

bonus: start checker
	@echo "Checker Good"

start:
	@cd ./ft_printf && make
	@cd ./libft && make

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(FTPRINTF) -o $(NAME)

checker: $(BOBJ) $(HEADER)
	@$(CC) $(BOBJ) $(LIBFT) $(FTPRINTF) -o checker

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaned"
	@$(RM) $(OBJ) $(BOBJ)
	@cd ./ft_printf && make clean
	@cd ./libft && make clean

fclean: clean
	@$(RM) $(NAME) checker
	@cd ./ft_printf && make fclean
	@cd ./libft && make fclean

re: fclean all

.PHONY: clean