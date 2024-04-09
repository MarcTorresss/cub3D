# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2024/04/07 18:25:04 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=vector.a

SRCDIR				:=.
SRCS				:=create_vector2d.c create_vector3d.c create_matrix2d.c \
					  create_matrix3d.c print_vector.c addition.c \
					  substraction.c dot_product.c dot_product2.c \
	 				  scalar_product.c transpose_mat.c length.c normalize.c \
					  cross_product.c determinant.c inverse.c adjacent.c \
					  distance.c rotate.c translate.c scale.c

OBJDIR				:=objs
OBJS				:=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))

TESTSRCS			:=test.c test1.c test2.c test3.c test4.c
TESTOBJS			:=$(patsubst %.c, $(OBJDIR)/%.o, $(TESTSRCS))

DEPS				:=$(OBJS:.o=.d)
DEPFLAGS			:=-MMD

INCLUDE				:=-I.
CC					:=cc
AR					:=ar rcs
#DEBUG				:=-fsanitize="address,undefined" -g
CFLAGS				:=-Wall -Werror -Wextra

all:				$(OBJDIR) $(NAME)

$(NAME):			$(OBJS) Makefile
						$(AR) $@ $(OBJS)
						echo "(VECTOR) COMPILING $@"
	
$(OBJDIR)/%.o:		$(SRCDIR)/%.c Makefile
						$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
						echo "(VECTOR) COMPILING $@"
	
$(OBJDIR)/%.o:		$(SRCDIR)/**/%.c Makefile
						$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
						echo "(VECTOR) COMPILING $@"

$(OBJDIR):			Makefile
						mkdir -p $@
	
test:				$(OBJDIR) $(NAME) $(TESTOBJS) Makefile
						$(CC) $(DEBUG) $(CFLAGS) -o $@ $(TESTOBJS) $(NAME)
						echo "(VECTOR) COMPILING $@"

clean:
						rm -rf $(OBJDIR)
						rm -f test

fclean:				clean
						rm -f $(NAME)

re:					fclean all

-include $(DEPS)

.PHONY:				all clean fclean re test
.SILENT:
