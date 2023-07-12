# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qtrinh <qtrinh@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/14 16:16:14 by qtrinh        #+#    #+#                  #
#    Updated: 2023/07/12 15:24:16 by qtrinh        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc
CFLAGS := -Wall -Werror -Wextra -g #gflag for debug

SRCS := main.c \
		list.c \
		parsing.c \
		utils.c \
		init_bruv.c \

OBJ := $(SRCS: .c=.o)

#COLORS SHOW
BOLD_GREEN=\033[1;92m
BOLD_RED=\033[1;91m
RED=\033[0;31m
PURPLE=\033[0;35m
YELLOW=\033[0;33m
GRAY=\033[0;37m
INTENSE_CYAN=\033[0;96m
END_COLOUR=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && (MAKE)
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "${RED}compiling? ${BOLD_GREEN}completed it mate ${END_COLOUR}"

%.o: %.C
	@echo "${RED} PUSHIN' $< ${END_COLOUR}"
	@$(CC) -c ${CFLAGS} $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "${INTENSE_CYAN}PUSHIN! ${END_COLOUR}"

re: fclean all

.PHONY: all clean fclean re
