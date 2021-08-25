# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:39:04 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/08/19 17:05:34 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

#CFLAGS = -Wall -Werror -Wextra

SERVER = server

CLIENT = client

LIBFT = ./libft/libft.a

SERVER_SOURCES = server.c

SERVER_SOURCES_BONUS = server_bonus.c

CLIENT_SOURCES = client.c

CLIENT_SOURCES_BONUS = client_bonus.c

all: $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT) $(PRINTFLIB) $(SERVER_SOURCES) 
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SOURCES) -Llibft -lft

$(CLIENT): $(LIBFT) $(PRINTFLIB) $(CLIENT_SOURCES) 
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SOURCES) -Llibft -lft

$(LIBFT):
	cd libft && $(MAKE) 
	cd libft && $(MAKE) bonus

clean:
	cd libft && $(MAKE) clean
	/bin/rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	/bin/rm -f $(NAME)

re: fclean all

bonus:
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_SOURCES_BONUS) -Llibft -lft
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_SOURCES_BONUS) -Llibft -lft
