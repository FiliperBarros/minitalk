LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./libft

NAME_SERVER= server
NAME_CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c 

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC= cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME_SERVER) $(NAME_CLIENT) 

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
