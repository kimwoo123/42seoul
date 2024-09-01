# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 15:35:05 by wooseoki          #+#    #+#              #
#    Updated: 2023/06/10 19:15:19 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = philo
CC = cc
RM = rm
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I ./
RMFLAGS = -rf
SRC = \
	  main.c set_var.c input_check.c utils.c monitoring.c \
	  ft_itoa.c eat_spaghetti.c live_philo_life.c print_philo_state.c \
	  control_thread.c clear_memory.c
OBJ_DIR = obj_dir/
SRC_DIR = ./

OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(OBJ_DIR) $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	
fclean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(RM) $(RMFLAGS) $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
