# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 11:06:38 by ipetruni          #+#    #+#              #
#    Updated: 2023/09/20 15:02:21 by ipetruni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP OF THE PROGRAM

NAME = pipex
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

# FILES AND PATH

HEARER_SRCS  = pipex.h
HEARER_DIR	 = includes/
HEADER		 = $(addprefix $(HEARER_DIR), $(HEARER_SRCS))

MPATH_SRCS 	= pipex.c pipex_error.c pipex_childs.c pipex_free.c
MPATH_DIR	= mandatory/
MPATH 		= $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M 		= $(MPATH:.c=.o)

FUNC_SRSC 	= ft_split.c ft_strdup.c ft_strncmp.c ft_substr.c ft_strlcpy.c ft_strjoin.c
FUNC_DIR	= functions/
FUNC 		= $(addprefix $(FUNC_DIR), $(FUNC_SRSC)) \
			gnl/get_next_line_utils.c gnl/get_next_line.c
OBJ_F		=$(FUNC:.c=.o)

# COMMANDS

%.o: %c $(HEADER) Makefile
	@${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ_F) $(OBJ_M)
	@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all: $(NAME)

clean:
	@$(RM) $(OBJ_M)
	@$(RM) $(OBJ_F)
	@echo -e "$(YELLOW)object files were deleted!$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "$(RED)$(NAME) deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

# COLORS DEFENITION

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
LIGHT_GREEN = \033[1;92m
