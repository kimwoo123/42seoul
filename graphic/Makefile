# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 14:10:39 by wooseoki          #+#    #+#              #
#    Updated: 2023/02/26 11:16:56 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
MLX = ./mlx/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm
RMFLAGS = -rf
HEADER = inc/fractol.h
SRC = \
	  main.c input_check.c hook.c \
	  put_pixel.c utils.c \

OBJ = $(SRC:.c=.o)
SRC_DIR = src/
OBJ_DIR = obj/
MLX_DIR = mlx/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
SRCS = $(addprefix $(SRC_DIR), $(SRC))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c -I $(MLX_DIR) $< -o $@

all : $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJS) $(MLX)
	$(CC) -L $(MLX_DIR) $(MLXFLAGS) $(OBJS) -o $(NAME)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
