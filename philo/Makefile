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

CFLAGS =			-g3 -Wall -Werror -Wextra

SRC_FILES =			philo.c \
					threads.c \
			 		utils.c \
					utils2.c \
					philo_routines.c \
					watcher_routines.c \
		
INCLUDE = 			philo.h

#.c.o: $(SRCS)
#	$(CC) $(CFLAGS) $(SRCS) -c $(OBJS) -o
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

define	ART
$(YELLOW)
                                                             
    _    ___            ___ ______  ___      _      ___  ___ 
  _| |_ (   )    /\    / _ \\  ___)/ _ \   _| |_   / _ \(   )
 /     \ | |    /  \  | | | |\ \  | | | | /     \ | | | || | 
( (| |) )| |   / /\ \ | | | | > > | | | |( (| |) )| | | || | 
 \_   _/ | |  / /  \ \| |_| |/ /__| |_| | \_   _/ | |_| || | 
   |_|  (___)/_/    \_\\___//_____)\___/    |_|    \___/(___)
                                                             
                                                             
 $(CLR_RMV)
endef
export	ART
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$$ART"
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re