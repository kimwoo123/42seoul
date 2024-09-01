# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wooseoki <wooseoki@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 16:31:06 by wooseoki          #+#    #+#              #
#    Updated: 2022/11/18 10:38:33 by wooseoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc
RM = rm
RMFLAGS = -f
HEADER = libft.h
SRCS = ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
        ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
        ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
        ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c
B_SRCS = ft_lstadd_back_bonus.c \
		 ft_lstadd_front_bonus.c \
		 ft_lstclear_bonus.c \
		 ft_lstdelone_bonus.c \
		 ft_lstiter_bonus.c \
		 ft_lstlast_bonus.c \
		 ft_lstmap_bonus.c \
		 ft_lstnew_bonus.c \
		 ft_lstsize_bonus.c
B_OBJS = $(B_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE)	all

bonus : $(NAME)

ifeq ($(filter $(MAKECMDGOALS), bonus), bonus)
$(NAME) : $(OBJS) $(B_OBJS)
	$(AR) $(ARFLAGS) $@ $^
else
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

.PHONY: all clean fclean re bonus
