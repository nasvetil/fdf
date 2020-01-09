NAME = fdf

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

HEADER = fdf.h

FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx
	make -C ./libft
	gcc $(OBJ) -o $(NAME) -L minilibx -lmlx -framework OpenGL -framework AppKit -L libft -lft

sanitize: $(OBJ)
	make -C ./minilibx
	make -C ./libft
	gcc -g $(OBJ) $(SANITIZE) -o $(NAME) -L minilibx -lmlx -framework OpenGL -framework AppKit -L libft -lft

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./minilibx fclean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all
