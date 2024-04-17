NAME        =    so_long

IDIR        =    so_long.h

SRCS		=	so_long.c \
				check_input.c \
				ft_libft.c \
				ft_split.c \
				init.c \
				checker_map.c \
				print.c \
				action.c \
				move.c \
				ft_strjoin.c \
				ft_itoa.c \


OBJS		=	$(SRCS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -g3 -Werror
RM			=	rm -f
NORM		=	norminette *.h && norminette *.c

MFLAGS 		= -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
MLX_PATH 	= ${MLX_DIR}/libmlx.a
MLX_DIR 	= mlx_linux




all			:	$(NAME)

$(NAME)		:	$(OBJS) make_mlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MFLAGS)

make_mlx	:
	@make -C ${MLX_DIR}

n			:
	$(NORM)

clean		:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY:		all clean fclean re
