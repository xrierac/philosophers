NAME	:= philo_bonus

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror

INC_DIR  := ./inc
SRC_DIR  := ./src
OBJ_DIR  := .
			
SRCS	:= $(SRC_DIR)/main.c $(SRC_DIR)/parsing.c $(SRC_DIR)/utils.c $(SRC_DIR)/init.c $(SRC_DIR)/exit.c $(SRC_DIR)/mutexes.c $(SRC_DIR)/threads.c $(SRC_DIR)/time.c $(SRC_DIR)/routines.c $(SRC_DIR)/print.c $(SRC_DIR)/watchdog.c
OBJS	:= ${SRCS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
