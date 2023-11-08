NAME = CUB3D
CC = gcc -fsanitize=address -g3 -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

SRC  =  cub.c parsing.c texters.c more_files.c libft/ft_bzero.c \
        libft/ft_strjoin.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_calloc.c \
        libft/ft_split.c libft/ft_strdup.c   libft/ft_strnstr.c libft/ft_strchr.c \
         file.c get_line/get_next_line.c -o cub3d


SRC_OBJ= $(SRC:.c=.o)
OBJ_BONUS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	ar rc $(NAME) $(SRC_OBJ)

clean:
	rm -f $(SRC_OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean clean all
