NAME	:= philo

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror

SRC_DIR  := .
OBJ_DIR  := .
			
SRCS	:= $(SRC_DIR)/philo.c
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
