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

# VARIABLES
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall \
		  -Wextra \
		  -Werror

SRCS_PATH	= srcs/
SRCS		= ASCII_functions/ft_isalpha.c				\
			  ASCII_functions/ft_isdigit.c				\
			  ASCII_functions/ft_isalnum.c				\
			  ASCII_functions/ft_isascii.c				\
			  ASCII_functions/ft_isprint.c				\
			  ASCII_functions/ft_toupper.c				\
			  ASCII_functions/ft_tolower.c				\
			  string_functions/ft_strlen.c				\
			  string_functions/ft_strlcpy.c				\
			  string_functions/ft_strlcat.c				\
			  string_functions/ft_strchr.c				\
			  string_functions/ft_strrchr.c				\
			  string_functions/ft_strncmp.c				\
			  string_functions/ft_strcmp.c				\
			  string_functions/ft_strnstr.c				\
			  string_functions/ft_strdup.c				\
			  string_functions/ft_appendchr.c			\
			  string_functions/ft_strndup.c				\
			  string_functions/ft_uitoa_base.c			\
			  memory_functions/ft_memset.c				\
			  memory_functions/ft_bzero.c				\
			  memory_functions/ft_memcpy.c				\
			  memory_functions/ft_memmove.c				\
			  memory_functions/ft_memchr.c				\
			  memory_functions/ft_memcmp.c				\
			  string_functions/ft_atoi.c				\
			  allocation_functions/ft_calloc.c			\
			  string_functions/ft_substr.c				\
			  string_functions/ft_strjoin.c				\
			  string_functions/ft_strtrim.c				\
			  string_functions/ft_strmapi.c				\
			  string_functions/ft_striteri.c			\
			  string_functions/ft_split.c				\
			  string_functions/ft_itoa.c				\
			  string_functions/ft_itoa_base.c			\
			  output_functions/ft_putchar_fd.c			\
			  output_functions/ft_putstr_fd.c			\
			  output_functions/ft_putendl_fd.c			\
			  output_functions/ft_putnbr_fd.c			\
			  linked_list_functions/ft_lstnew.c			\
			  linked_list_functions/ft_lstadd_front.c	\
			  linked_list_functions/ft_lstsize.c		\
			  linked_list_functions/ft_lstlast.c		\
			  linked_list_functions/ft_lstadd_back.c	\
			  linked_list_functions/ft_lstdelone.c		\
			  linked_list_functions/ft_lstclear.c		\
			  linked_list_functions/ft_lstiter.c		\
			  linked_list_functions/ft_lstmap.c			\
			  get_next_line/get_next_line.c				\
			  get_next_line/get_next_line_utils.c

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
vpath %.c $(SRCS_PATH)

INCLUDE	= -I./includes/

# COMPILATION
$(NAME)	: message $(OBJS)
	@echo "$(_GREEN)[Libft: Compilation finished]$(_NO_COLOR)"
	@ar cr $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(_PURPLE)[Libft: $(NAME) created]$(_NO_COLOR)"

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)ASCII_functions
	@mkdir -p $(OBJS_PATH)allocation_functions
	@mkdir -p $(OBJS_PATH)linked_list_functions
	@mkdir -p $(OBJS_PATH)memory_functions
	@mkdir -p $(OBJS_PATH)output_functions
	@mkdir -p $(OBJS_PATH)string_functions
	@mkdir -p $(OBJS_PATH)get_next_line
#	@echo "$(_GREY)Compiling : $<$(_NO_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# RULES
all		: $(NAME)

message	:
	@echo "$(_YELLOW)[Libft: Compilation ongoing ...]$(_NO_COLOR)"

clean	:
	@rm -rf $(OBJS_PATH)
	@echo "$(_RED)[Libft: All objects removed]$(_NO_COLOR)"

fclean	: clean
	@rm -f $(NAME)
	@echo "$(_RED)[Libft: $(NAME) removed]$(_NO_COLOR)"

re		: fclean all

.PHONY	: all clean fclean re
