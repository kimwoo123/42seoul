# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 18:19:43 by wooseoki          #+#    #+#              #
#    Updated: 2023/02/12 17:27:24 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
SRC = \
	  cmd1.c cmd2.c cmd3.c \
	  main.c greedy.c ps_atoi.c \
	  list.c utils.c rotate.c \
	  manual_sort.c init.c\

BONUS_SRC = \
			checker_bonus.c list_bonus.c ps_atoi_bonus.c \
			cmd1_bonus.c cmd2_bonus.c cmd3_bonus.c utils_bonus.c \

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ_DIR = ./obj/
B_OBJ_DIR = ./bobj/
LIB_DIR = ./libft/
SRC_DIR = ./src/
BONUS_DIR = ./bns/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
BONUS_OBJS = $(addprefix $(B_OBJ_DIR), $(BONUS_OBJ))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)%.o : $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(OBJ_DIR) $(NAME)

bonus : $(B_OBJ_DIR) $(BONUS)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(BONUS) : $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(B_OBJ_DIR):
	mkdir $(B_OBJ_DIR)

clean : 
	$(RM) $(RMFLAGS) $(OBJ_DIR) $(B_OBJ_DIR)

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(RMFLAGS) $(NAME) $(BONUS)

re :
	$(MAKE) fclean
	$(MAKE) all
