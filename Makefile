#-------- push_swap --------#
NAME	=	push_swap
SRC		=	push_swap.c push_swap_prep.c init_stack.c actions.c error.c
OBJ		=	$(SRC:.c=.o)

#--------- library ---------#
LIBFT	=	./libft/libft.a

#---------- other ----------#
//CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

#---------- rules ----------#

all: $(NAME) 

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@gcc -g $(CFLAGS) -c $(SRC)
	@echo "objetos creados :D"

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
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