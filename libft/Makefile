# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 18:13:35 by pfontenl          #+#    #+#              #
#    Updated: 2024/02/21 11:38:50 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
FLAGS 	= -Wall -Wextra -Werror -I .
INCLUDE = libft.h
CC = gcc
LIB = ar rcs

DIR_PRINTF = printf/
DIR_GETNL = get_next_line/
DIR_OBJ = temp/

SRC_LIBFT = ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_memset.c ft_tolower.c ft_toupper.c ft_memcpy.c\
ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_memmove.c ft_strlcpy.c ft_strchr.c\
ft_strrchr.c ft_memchr.c ft_itoa.c ft_substr.c ft_memcmp.c ft_putchar_fd.c ft_strcmp.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_split.c ft_strjoin.c\
ft_strtrim.c ft_calloc.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_join_n_destroy.c\
ft_strlenz.c\


FILES_PRINTF = ft_fprintf.c ft_numutils.c ft_utils.c\

FILES_GETNL = get_next_line.c get_next_line_utils.c\


SRC_PRINTF = $(addprefix $(DIR_PRINTF), $(FILES_PRINTF))

SRC_GETNL = $(addprefix $(DIR_GETNL), $(FILES_GETNL))


OBJ_LIBFT = $(addprefix $(DIR_OBJ), $(SRC_LIBFT:.c=.o))

OBJ_PRINTF =  $(addprefix $(DIR_OBJ), $(SRC_PRINTF:.c=.o))

OBJ_GETNL = $(addprefix $(DIR_OBJ), $(SRC_GETNL:.c=.o))


all: temp $(NAME)

temp:
	@mkdir -p $(DIR_OBJ)
	
$(NAME): $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GETNL)
	@$(LIB) $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GETNL)
	@echo "\033[1;34mLibft Printf GetNL \033[0;32mcompiled\033[0m ✅\n"

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[0;33mCompiling\033[0m $< ..."

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
