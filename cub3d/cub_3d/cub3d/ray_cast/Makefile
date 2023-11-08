CC = cc
CFLAGS =  -fsanitize=address  -g3 #-Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -f
FILES = lunchmap.c cub3d.c leaks.c ../parsing.c ../texters.c ../more_files.c ../libft/ft_bzero.c \
        ../libft/ft_strjoin.c ../libft/ft_atoi.c ../libft/ft_strlen.c ../libft/ft_calloc.c \
        ../libft/ft_split.c ../libft/ft_strdup.c   ../libft/ft_strnstr.c ../libft/ft_strchr.c \
         ../file.c ../get_line/get_next_line.c ../libft/ft_itoa.c
OBJ = $(FILES:.c=.o)
NAME = cub3d

all: $(NAME)

UNAME = $(shell uname)
ifeq ($(UNAME),Linux)
    MLX_FLAGS = -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif


$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(FILES) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
