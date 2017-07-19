# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/18 10:57:42 by dgerard           #+#    #+#              #
#    Updated: 2017/07/18 10:57:44 by dgerard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = 	

OFILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo "\033[32m[libftprintf created ( ͡° ͜ʖ ͡°)]\033[0m"

%.o: %.c
	@gcc $(CFLAGS) -c $^ -o $@
	@/bin/echo -n "❂❂❂"

clean:
	@rm -f $(OFILES)
	@echo "\033[31m[.o files deleted (╯°□°）╯︵ ┻━┻ ]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[libftprintf deleted ᕙ(⇀‸↼‶)ᕗ ]\033[0m"

re: fclean all
