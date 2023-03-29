# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irmoreno <irmoreno@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 13:25:49 by irmoreno          #+#    #+#              #
#    Updated: 2023/03/29 20:03:15 by irmoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------- push_swap --------#
NAME	=	push_swap
SRC		=	./src/push_swap.c ./src/push_swap_prep.c ./src/init_stack.c\
			./src/actions.c ./src/positions.c	./src/push.c ./src/utils.c\
			./src/do_actions.c
OBJ		=	$(SRC:.c=.o)

#--------- library ---------#
LIBFT	=	./libft/libft.a

#---------- other ----------#
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

#---------- rules ----------#

all: $(NAME) 

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@gcc -g $(CFLAGS) -c $(SRC)
	@echo "objetos creados :D"

$(NAME): $(OBJ) $(LIBFT)
	@gcc -g $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "push_swap creado :D"

clean:
	@$(RM) $(OBJ)
	@echo "objetos eliminados :D"

fclean: clean
	@$(RM) $(NAME)
	@echo "push_swap eliminado :D"

re: fclean all

libclean:
	@make -C ./libft fclean
	@echo "librerías eliminadas :D"

.PHONY: all clean fclean re