CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c server.c utils.c
BONUS_SRCS = client_bonus.c server_bonus.c utils.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = client server
BONUS_NAME = client_bonus server_bonus

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) client.o utils.o -o client
	$(CC) $(CFLAGS) server.o utils.o -o server

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) client_bonus.o utils.o -o client_bonus
	$(CC) $(CFLAGS) server_bonus.o utils.o -o server_bonus

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
