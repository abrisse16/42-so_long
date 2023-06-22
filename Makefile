# COLORS
_GREY		=	$'\033[1;30m
_RED		=	$'\033[1;31m
_GREEN		=	$'\033[1;32m
_YELLOW		=	$'\033[1;33m
_BLUE		=	$'\033[1;34m
_PURPLE		=	$'\033[1;35m
_CYAN		=	$'\033[1;36m
_WHITE		=	$'\033[1;37m
_NO_COLOR	=	$'\033[m

# VARIABLE
NAME	= so_long

CC		= gcc

CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -MMD		\
		  -g
IFLAGS	= -I includes/ -I libft/includes/ -I mlx_linux/
LDFLAGS = -L libft -lft -L mlx_linux -lmlx -lXext -lX11 -lm

SRCS_PATH	= srcs/
OBJS_PATH	= objs/
DEP_PATH	= deps/

LIBFT		= libft/libft.a
MLX			= mlx_linux/libmlx.a
SRCS		= main.c			\
			  error.c			\
			  init.c			\
			  checking_map.c	\
			  parsing.c			\
			  display.c			\
			  action.c			\
			  free.c
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
DEP			= $(addprefix $(DEP_PATH), $(SRCS:.c=.o))
vpath %.c $(SRCS_PATH)

# COMPILATION
$(NAME)	: $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	@echo "$(_GREEN)[so_long: Executable created]$(_NO_COLOR)"

$(LIBFT):
	@make -C libft

$(MLX)	:
	@make -C mlx_linux all

$(OBJS_PATH)%.o : %.c
	@mkdir -p $(OBJS_PATH) $(DEP_PATH)
	@echo "$(_GREY)Compiling : $<$(_NO_COLOR)"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

# RULES
all		: $(NAME)

clean	:
	@make -C libft/ clean
	@make -C mlx_linux clean
	@rm -rf  $(OBJS_PATH)
	@rm -rf  $(DEP_PATH)
	@echo "$(_RED)[so_long: All objects removed]$(_NO_COLOR)"

fclean	: clean
	@make -C libft/ fclean
	@make -C mlx_linux clean
	@rm -rf $(NAME)
	@echo "$(_RED)[so_long: Executable removed]$(_NO_COLOR)"

re		: fclean all

.PHONY	: all clean fclean re
