# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:22:46 by wooseoki          #+#    #+#              #
#    Updated: 2022/12/05 11:20:26 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
SRCS = \
	   man_srcs/ft_printf.c \
	   man_srcs/ft_prascii.c \
	   man_srcs/ft_prnum.c
B_SRCS = \
		 bo_srcs/ft_printf_bonus.c \
		 bo_srcs/parce_bonus.c \
		 bo_srcs/util_bonus.c \
		 bo_srcs/convert_c_bonus.c \
		 bo_srcs/convert_i_bonus.c \
		 bo_srcs/convert_p_bonus.c \
		 bo_srcs/convert_s_bonus.c \
		 bo_srcs/convert_u_bonus.c \
		 bo_srcs/convert_x_bonus.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)
	
bonus : $(NAME)

ifeq ($(filter $(MAKECMDGOALS), bonus), bonus)
$(NAME): $(B_OBJS)
	$(RM) $(NAME) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
else
$(NAME) : $(OBJS)
	$(RM) $(NAME) $(B_OBJS)
	$(AR) $(ARFLAGS) $@ $^
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) clean
	$(MAKE) all

