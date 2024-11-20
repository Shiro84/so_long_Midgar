# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matomas <matomas@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 19:43:58 by matomas           #+#    #+#              #
#    Updated: 2024/10/30 10:37:49 by matomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_MAND = ft_memset.c		\
		  		ft_memmove.c	\
		  		ft_memchr.c		\
		  		ft_memcmp.c		\
		  		ft_memcpy.c		\
		  		ft_memcpy.c		\
		  		ft_bzero.c		\
		  		ft_atoi.c		\
		  		ft_strlen.c		\
		  		ft_strlcpy.c	\
		  		ft_strlcat.c	\
		 	 	ft_strchr.c		\
		 		ft_strrchr.c	\
		  		ft_strnstr.c	\
				ft_strncmp.c	\
		  		ft_isalnum.c	\
		  		ft_isdigit.c	\
		  		ft_isalpha.c	\
		  		ft_isascii.c	\
		 		ft_isprint.c	\
		  		ft_tolower.c	\
		  		ft_toupper.c	\
		  		ft_calloc.c		\
		  		ft_strdup.c		\
				ft_itoa.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_striteri.c	\

SRCS_BONUS = ft_lstnew_bonus.c \
		 		ft_lstadd_front_bonus.c \
		 		ft_lstsize_bonus.c \
		 		ft_lstlast_bonus.c \
		 		ft_lstadd_back_bonus.c \
		 		ft_lstdelone_bonus.c \
		 		ft_lstclear_bonus.c \
		 		ft_lstiter_bonus.c \
		 		ft_lstmap_bonus.c \

OBJS_MAND = ${SRCS_MAND:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC = gcc
RM = rm -rf
AR = ar rcs
RANLIB = ranlib 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJS_MAND)
	$(AR) $(NAME) $(OBJS_MAND)
	$(RANLIB) $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS_MAND)
	rm -f $(OBJS_BONUS)
	@echo "OBJS_MAND deleted"

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re
