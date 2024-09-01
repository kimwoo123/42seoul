# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 21:22:07 by wooseoki          #+#    #+#              #
#    Updated: 2023/01/21 18:47:26 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIB_DIR = ./libft
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc
RM = rm
RMFLAGS = -f
SRCS = \
	   pipex.c \
	   utils.c \
	   error_exit.c \
	

OBJS = $(SRCS:.c=.o)

all : $(NAME)

debug : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(RMFLAGS) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

ifeq ($(MAKECMDGOALS), debug)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g $(LIBFT) $(SRCS) -o $@
else
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@
endif

$(LIBFT) :
	$(MAKE) -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
