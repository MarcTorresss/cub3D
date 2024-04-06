# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/13 23:55:40 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=cub3D

SRCDIR			:=src
SRCS			:=main.c check_elements.c check_fill.c check_map.c utils_map.c \
			  draw.c hit.c image.c key_hook.c player.c ray.c

OBJDIR			:=objs
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

DEPS			:=$(OBJS:.o=.d)
DEPFLAGS		:=-MMD

CC				:=gcc
CFLAGS			:=-Wall -Werror -Wextra
DEBUG			:=-g -fsanitize=address

INCS			:=-I./inc -I./libft -I./vector -I./mlx_linux
LIBS			:=-Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz

all: 			$(OBJDIR) libft vector minilibx $(NAME)

$(NAME):		$(OBJS) Makefile
					$(CC) $(CFLAGS) $(DEBUG) $(OBJS) libft/libft.a vector/vector.a -o $(NAME) $(LIBS) $(INCS)
					echo "(CUB3D) COMPILING $@"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D) COMPILING $@"

$(OBJDIR)/%.o:	$(SRCDIR)/raycasting/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D) COMPILING $@"

$(OBJDIR):		Makefile
					mkdir -p $@

libft:
					make -C libft

vector:
					make -C vector

minilibx:
					make -C mlx_linux

clean:
					make -C libft fclean
					make -C vector fclean
					make -C mlx_linux clean
					rm -rf $(OBJDIR)

fclean:			clean
					rm -f $(NAME)

re:				fclean all

-include $(DEPS)

.PHONY:			all clean fclean re libft vector minilibx
.SILENT: