# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 17:31:34 by martorre          #+#    #+#              #
#    Updated: 2024/04/02 17:38:21 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
RM		=	rm -fr

NAME		=	cub3D
COMP		=	./libft/libft.a
INC			=	./inc/cub3D.h

DIR_OBJ		=	obj/
DIR_SRC		=	src/

# *******************************	FILES	******************************* #

FILES		=	main.c check_map.c

FILES_SRC	=	$(addprefix $(DIR_SRC),$(FILES))

# *********************************	OBJECTS	****************************** #

OBJ			=	$(addprefix $(DIR_OBJ),$(FILES_SRC:.c=.o))

# *******************************  COLORS	******************************* #

RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
RESET		=	\033[0m
GREEN_BOLD	=	\033[1;32m
BLUE_BOLD	=	\033[1;34m
CYAN_BOLD	=	\033[1;36m

# *******************************  RULES ******************************* #

all : $(DIR_OBJ) lib $(NAME)

lib :
	$(MAKE) -C ./libft --no-print-directory

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(COMP) -o $@

	@echo "${BLUE_BOLD}cub3D ${GREEN}compiled ✅\n${RESET}"

$(DIR_OBJ)%.o: %.c Makefile $(INC)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${YELLOW}Compiling ${RESET}$@...${RESET}"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean	:
	@$(MAKE) -C libft clean --no-print-directory
	@$(RM) $(DIR_OBJ)
	@echo "${RED}Deleting${RESET} all objects 🗑"

fclean	: clean
	@$(MAKE) -C libft fclean --no-print-directory
	@$(RM) $(NAME) 
	@echo "${BLUE_BOLD}cub3D ${RED}deleted${RESET}"

norm	:
	@printf "${PURPLE}SEARCHING FOR A PRINTF IN THE PROJECT: "
	@printf "%i \n${RESET}" $(shell grep "	printf" *.c | wc -l)
	@printf "${YELLOW}Norminette...\n${RESET}"
	@printf "${RED}"
	@norminette src/*/*.c src/*.c inc/*.h > test && printf "$(GREEN)\t[OK]\n" || grep Error test
	@printf "${RESET}"
	@rm test

re		: fclean
	@$(MAKE) all

.PHONY : all clean fclean re lib
