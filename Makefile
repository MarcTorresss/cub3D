# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/16 11:25:06 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=cub3D

SRCDIR			:=src
SRCS			:=main.c check_elements.c check_map.c utils_map.c utils_map2.c \
				  utils_elements.c draw.c hit.c image.c render.c player.c ray.c \
				  draw_field.c free_mlx.c listen_input.c check_transform.c \
				  key_input.c free_all.c set_scene.c
          
BONUS			:=.bonus

BONUS_SRCDIR	:=src_bonus
BONUS_SRCS		:=main_bonus.c check_elements.c check_map.c utils_map2.c\
				  utils_map.c check_map_bonus.c hit.c image.c render_bonus.c \
				  player.c ray.c draw_field.c free_mlx.c listen_input_bonus.c \
				  draw_bonus.c draw_minimap_bonus.c draw_square_bonus.c \
				  key_input.c draw_triangle_bonus.c check_transform.c \
				  mouse_input_bonus.c utils_elements.c free_all.c set_scene_bonus.c\

OBJDIR			:=.objs
OBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
BONUS_OBJS		:=$(patsubst %.c, $(OBJDIR)/%.o, $(BONUS_SRCS))

DEPS			:=$(OBJS:.o=.d)
DEPS			+=$(BONUS_OBJS:.o=.d)
DEPFLAGS		:=-MMD

CC				:=gcc
CFLAGS			:=-Wall -Werror -Wextra 
DEBUG			:=-g -fsanitize=address

INCS			:=-I./inc -I./libft -I./vector -I./mlx_linux -I./mlx
MLXLIB			:=-Lmlx -lmlx -framework OpenGL -framework AppKit
#MLXLIB			:=-Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lz
LIBS			:=libft/libft.a vector/vector.a $(MLXLIB)

all: 			$(OBJDIR) libft vector minilibx $(NAME)

$(NAME):		$(OBJS) Makefile
					$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LIBS) $(INCS) -o $(NAME)
					echo "(CUB3D) COMPILING $@"

$(OBJDIR)/%.o:	$(SRCDIR)/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D) COMPILING $@"

$(OBJDIR)/%.o:	$(SRCDIR)/render/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D) COMPILING $@"

$(OBJDIR)/%.o:	$(SRCDIR)/listen_input/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D) COMPILING $@"

bonus:			$(OBJDIR) libft vector minilibx $(BONUS)

$(BONUS):		$(BONUS_OBJS) Makefile
					$(CC) $(CFLAGS) $(DEBUG) $(BONUS_OBJS) \
						$(LIBS) $(INCS) -o $(NAME)
					echo "(CUB3D_BONUS) COMPILING $(NAME)"
					touch $@

$(OBJDIR)/%.o:	$(BONUS_SRCDIR)/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D_BONUS) COMPILING $@"

$(OBJDIR)/%.o:	$(BONUS_SRCDIR)/render/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D_BONUS) COMPILING $@"

$(OBJDIR)/%.o:	$(BONUS_SRCDIR)/listen_input/%.c Makefile
					$(CC) $(DEPFLAGS) $(CFLAGS) $(INCS) -c $< -o $@
					echo "(CUB3D_BONUS) COMPILING $@"

$(OBJDIR):		Makefile
					mkdir -p $@

libft:
					make -C libft --no-print-directory

vector:
					make -C vector --no-print-directory

minilibx:
					make -C mlx --no-print-directory

clean:
					make -C libft fclean
					make -C vector fclean
					make -C mlx clean
					rm -rf $(OBJDIR)

fclean:			clean
					rm -f $(NAME)
					rm -f $(BONUS)

re:				fclean all

-include $(DEPS)

.PHONY:			all clean fclean re libft vector minilibx
.SILENT: