# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ducnguye <ducnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 19:43:27 by ducnguye          #+#    #+#              #
#    Updated: 2024/09/16 19:43:40 by ducnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Must not relink ??

# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = srcs
OBJ_DIR = obj
INCLUDE_DIR = includes

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/display_map.c

# Object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
NAME = my_program

# Default rule
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

# Rule to compile .c files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and directory
clean:
	rm -f $(OBJ_FILES)
	rmdir --ignore-fail-on-non-empty $(OBJ_DIR)

# Remove executable, object files, and directory
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
