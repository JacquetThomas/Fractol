MLX_FLAG	=	-lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Wextra -Wall -Werror -O3 -Ofast
INCL		=	fractol.h
LIB_FLAG	=	-Ilibft/ libft/libft.a
SRCS		=	main.c \
				error.c \
				str_tools.c \
				mlx.c \
				draw.c \
				key_hook.c \
				mouse_hook.c \
				free_x.c \
				init.c \
				mandelbrot.c \
				julia.c \
				burning_ship.c \
				newton.c \
				complex_calc.c \
				color.c \
				again.c \
				help.c
OBJ			=	$(SRCS:.c=.o)
NAME		=	fractol

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(CFLAGS) -c $(SRCS) -include $(INCL)
	gcc $(CFLAGS) $(OBJ) $(MLX_FLAG) $(LIB_FLAG) -o $(NAME)

clean :
	make -C libft/ clean
	make -C minilibx_sierra/ clean
	make -C minilibx/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all

debug :
	make -C libft/
	gcc $(CFLAGS) -g -c $(SRCS) -include $(INCL)
	gcc $(CFLAGS) -g $(OBJ) $(MLX_FLAG) $(LIB_FLAG) -o $(NAME)
	lldb fdf

sierra :
	make -C libft/
	make -C minilibx_sierra/
	gcc $(CFLAGS) -c $(SRCS) -include $(INCL)
	gcc $(CFLAGS) $(OBJ) -lm -Iminilibx_sierra/ minilibx_sierra/libmlx.a -framework OpenGL -framework AppKit $(LIB_FLAG) -o $(NAME)

test : fclean
	make -C libft/
	make -C minilibx_sierra/
	gcc $(CFLAGS) -c test/*.c -include $(INCL)
	gcc $(CFLAGS) *.o -lm -Iminilibx_sierra/ minilibx_sierra/libmlx.a -framework OpenGL -framework AppKit $(LIB_FLAG) -o $(NAME)
	./fdf
