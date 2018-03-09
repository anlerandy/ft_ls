# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 14:52:44 by alerandy          #+#    #+#              #
#    Updated: 2018/03/09 12:05:37 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = main.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc $(FLAG)
LIB = -Iincludes -Ilibft/includes
FLAG = -Wall -Werror -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libft $(OBJ)
	@$(CC) $(LIB) $(OBJ) -o $(NAME)
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|----------- $(NAME) crée ------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

libft :
	@$(MAKE) -j -C libft/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(LIB) -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C libft/ fclean

re : fclean $(NAME)
	@printf "\033[\r\033[K""\033[32mLibrairie mlx compilé avec succès.\033[0m\n"

norm :
	@clear
	@norminette srcs/ includes/

norml :
	@clear
	@norminette libft/srcs/ libft/includes/

normall :
	@clear
	@norminette srcs/ includes/
	@norminette libft/srcs/ libft/includes/

.PHONY : fclean clean re norm norml norm normall all
