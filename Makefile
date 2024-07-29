NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBG = -g -fsanitize=address
IFLAGS = -I includes
DEPFLAGS = -MMD -MP
RM = rm -rf

SRC = main\
	err\
	init\
	parse\
	elements\
	texture\
	rgb\
	free\
	map\
	check_map\
	player\
	display\
	raycasting\
	buffer\
	render
SRCS = $(addprefix srcs/,$(addsuffix .c,$(SRC)))
OBJS = $(addprefix srcs/,$(addsuffix .o,$(SRC)))
DEPS = $(addprefix srcs/,$(addsuffix .d,$(SRC)))

LIB = ./libft/libft.a
MLX = ./mlx/libmlx.a

all : mandatory

mandatory : $(OBJS) $(LIB) $(MLX)
	@$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)
	@if [ -e bonus ]; then \
		rm bonus; \
	fi
	@touch mandatory
	@echo "Made cub3D"
-include $(DEPS)

d : $(LIB) $(MLX)
	@$(CC) $(DBG) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ $(SRCS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	
$(LIB) : 
	@$(MAKE) -C ./libft
	@$(MAKE) bonus -C ./libft

$(MLX) : 
	@$(MAKE) -C ./mlx

clean :
	@$(RM) $(OBJS) $(DEPS) mandatory
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./mlx
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "fcleaned"

re : fclean all