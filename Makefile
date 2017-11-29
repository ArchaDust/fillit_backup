# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
<<<<<<< HEAD
#    Created: 2017/11/29 11:35:47 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2017/11/29 11:41:59 by aberneli    ###    #+. /#+    ###.fr      #
=======
#    Created: 2017/11/28 15:38:00 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2017/11/28 15:44:24 by aberneli    ###    #+. /#+    ###.fr      #
>>>>>>> a54ec7e58c933b0872b6cfdc4ba4f3984ddc2104
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

<<<<<<< HEAD
.PHONY: all clean fclean re

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = conformity.c fillit.c ft_showit.c lst_clear.c map.c utils.c \
	   utils_three.c utils_two.c

OBJS = $(SRCS:.c=.o)

HEADERS = fillit.h types.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
=======
NAME = fillit

SRCS = ft_showit.c map.c utils_three.c conformity.c lst_clear.c utils.c \
	  utils_two.c fillit.c

OBJS = $(SRCS:.c=.o)

HEAD = fillit.h types.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEAD)
>>>>>>> a54ec7e58c933b0872b6cfdc4ba4f3984ddc2104
	gcc $(FLAGS) $(OBJS) -o $(NAME)

./%.o: ./%.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
