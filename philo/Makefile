# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imontero <imontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 16:14:07 by imontero          #+#    #+#              #
#    Updated: 2023/09/08 13:26:44 by imontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				philo

CC = 				gcc

#CFLAGS =			-g3 -Wall -Werror -Wextra #-fsanitize=address 
CFLAGS =			-g3 -Wall -Werror -Wextra -fsanitize=thread

SRC_FILES =			philo.c \
					inits.c \
					threads.c \
			 		utils.c \
					utils2.c \
					routines.c \
					
				
		
INCLUDE = 			philo.h

OBJS = $(SRC_FILES:.c=.o)

#.c.o: $(SRCS)
#	$(CC) $(CFLAGS) $(SRCS) -c $(OBJS) -o

all: $(NAME)


$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re