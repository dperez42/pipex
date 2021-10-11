# NAMES ====================================================================================
NAME	=	pipex
# COMPILADOR ====================================================================================
CC			=	gcc
# INCLUDES ====================================================================================
INCS_DIR = ./pipex.h
INCLUDES = -I$(INCS_DIR)
# FLAGS ====================================================================================
FLAGS 		= -Wall -Wextra -Werror
# PATHS ============================
SRCS_DIR 	= 	./
SRCS 		=  	main.c \
				ft_aux.c \
				ft_parse.c \
				ft_split.c \
				ft_create_pid.c \
				ft_param.c
SRCS_ALL	=	$(addprefix $(SRCS_DIR), $(SRCS)) 

# COLOURS ====================================================================================

RED = \033[0;31m
REDBOLD = \033[1;31m
GREEN = \033[0;32m
GREENBOLD = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m
PURPLE = \033[0;35m
YELLOW = \033[0;33m

# OBJS =====================================================================================
OBJS_DIR 		= 	./
OBJS			=	$(SRCS_ALL:.c=.o)
OBJS_ALL 		= 	$(addprefix $(OBJS_DIR), $(OBJS))

# ==========================================================================================

# FROM SUBJECT =============================================================================
all: $(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS_ALL)

clean:
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS) $(RED) removed. $(RESET)"
	@/bin/rm -rf $(OBJS)
fclean: clean
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME) $(GREEN) removed. $(RESET)"
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

# testing ======================================================================================

# ==========================================================================================
