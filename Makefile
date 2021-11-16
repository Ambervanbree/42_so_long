# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 14:38:04 by avan-bre          #+#    #+#              #
#    Updated: 2021/10/25 15:28:12 by avan-bre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 EXECUTABLES                                  #
################################################################################

OS		=	$(shell uname -s)
NAME	=	so_long
BONUS	=	so_long_b
LIBFT	=	libft/libft.a

ifeq ($(OS), Linux)
	MLX		=	mlx/libmlx_Linux.a
else
	MLX		=
endif

ifeq ($(OS), Linux)
	CL_MLX	=	@make clean -s -C mlx
else
	CL_MLX	=
endif


################################################################################
#                                 COMMANDS                                     #
################################################################################

RM		=	@rm -rf

ifeq ($(OS), Linux)
	CC		=	@clang
else
	CC		=	@gcc
endif

################################################################################
#                                 FLAGS                                        #
################################################################################

CFLAGS	:=	-Wall -Werror -Wextra
LFLAGS	:=	-Llibft -lft

ifeq ($(OS), Linux)
	MFLAGS	:=	-L. -lmlx -L/usr/lib -lXext -lX11 -lm
else
	MFLAGS	:= -lmlx -framework OpenGL -framework AppKit
endif


################################################################################
#                                 FILES                                        #
################################################################################

INC		=	so_long.h libft/libft.h
SRCS	=	main.c init_game.c events_game.c key_events.c check_utils.c \
			exit_utils.c
B_SRCS	=	main_b.c init_game_b.c events_game_b.c key_events_b.c \
			check_utils_b.c exit_utils_b.c string_b.c
S_DIR	=	sources/
B_DIR	=	bonus/
OBJS	=	$(addprefix $(S_DIR), $(SRCS:.c=.o))
B_OBJS	=	$(addprefix $(B_DIR), $(B_SRCS:.c=.o))

################################################################################
#                                 RULES                                        #
################################################################################

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	@echo "Compiling sources.."
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(MFLAGS)
	@echo "Ready!"

$(LIBFT):
	@echo "Compiling libft.."
	@make -s -C libft
	@echo "Libft ready!"

$(MLX):
	@echo "Compiling mlx.."
	@make -s -C mlx
	@echo "Mlx ready!"


$(BONUS):	$(LIBFT) $(MLX) $(B_OBJS) 
	@echo "Compiling bonus sources.."
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS) $(MFLAGS)
	@echo "Ready!"


bonus:	$(BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	$(CL_MLX)
	@make $@ -s -C libft
	@echo "Removed objects"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@make $@ -s -C libft
	@echo "Removed executable files"

re:		clean all

.PHONY:	re, all, clean, fclean, bonus
