# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 11:35:47 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 11:41:59 by aberneli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = conformity.c fillit.c ft_showit.c lst_clear.c map.c utils.c \
	   utils_three.c utils_two.c

OBJS = $(SRCS:.c=.o)

HEADERS = fillit.h types.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

./%.o: ./%.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
