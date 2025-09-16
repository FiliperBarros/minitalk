# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 12:27:02 by frocha-b          #+#    #+#              #
#    Updated: 2025/09/16 10:57:07 by frocha-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Include directory
INCLUDE_DIR = includes

# Libft paths
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Executable names
NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

# Source directories
SRC_DIR = ./src
SRC_BONUS_DIR = ./src_bonus

# Source and object files (normal)
SRCS_CLIENT = \
	$(SRC_DIR)/client.c \
	$(SRC_DIR)/exit_error.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER = \
	$(SRC_DIR)/server.c \
	$(SRC_DIR)/exit_error.c
	
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Source and object files (bonus)
SRCS_CLIENT_BONUS = \
	$(SRC_BONUS_DIR)/client_bonus.c \
	$(SRC_BONUS_DIR)/exit_error_bonus.c
	
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

SRCS_SERVER_BONUS = \
	$(SRC_BONUS_DIR)/server_bonus.c \
	$(SRC_BONUS_DIR)/exit_error_bonus.c


OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDE_DIR)

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(LIBFT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

# Full clean including executables and libft
fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

# Rebuild all normal targets
re: fclean all

# Rebuild bonus targets
re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus