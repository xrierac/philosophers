NAME	:= philo

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror

INC_DIR  := ./inc
SRC_DIR  := ./src
OBJ_DIR  := .
			
SRCS	:= $(SRC_DIR)/main.c $(SRC_DIR)/parsing.c $(SRC_DIR)/parsing_utils.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/init.c $(SRC_DIR)/exit.c
OBJS	:= ${SRCS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
