NAME = filler

SRC = filler.c	board.c token.c place_token.c check_token.c get_start_pos.c	

LIBS = -L./libft -lft 

FLAGS = -Wall -Werror -Wextra $(LIBS)

HEADERS = filler.h

all : $(NAME)

$(NAME) :
	make -C ./libft/
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	make clean -C ./libft/

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
	make re -C ./libft/
