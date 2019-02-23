
NAME   = fillit

NAME2 = libft.a

MAKELIB = -f ./makefile

SRC	 = 	ft_fillitmain.c ft_validation.c ft_error.c ft_read.c ft_createlist.c ft_createmap.c ft_solve.c ft_free.c ft_validcrunch.c\

SRCLIB = ./libft/

NAME2SRC = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = fillt.h

HEADERLIB = ./libft/libft.h

OBJ = $(SRC:.c=.o)

OBJ2 = ./libft/*.o

all: $(NAME)

$(NAME): $(NAME2) $(OBJ)
	$(CC) $(FLAGS) $(SRC) -L $(SRCLIB) -lft -I $(HEADER) -I $(HEADERLIB) -o $(NAME)

$(NAME2):
	 $(MAKE) -C ./libft 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	
	rm -f $(NAME)
	rm -f $(NAME2SRC)

re: fclean all


