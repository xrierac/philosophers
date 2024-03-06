NAME	:= philo

#Compiler options#

CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror

SRCDIR  := ./philo
			
SRCS	:= $(shell find ./philo -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
HEADER  := ./philo/philo.h

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
