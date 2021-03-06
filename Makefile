NAME = fillit

INC_DIR = inc/

SRC_DIR = ./src/

SRC_FILES = main.c \
 			get_tetriminos.c \
 			get_tetriminos2.c \
 			get_tetriminos3.c \
 			op_on_map.c \
 			print_solved_map.c \
 			recursive_solver.c

O_FILES = $(SRC_FILES:.c=.o)

CC = clang

CC_FLAGS = -Wall -Werror -Wextra

I_LIBFT = -Ilibft

LIBFT = -Llibft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)
	@echo "$(NAME) is ready :)"

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
