SRCS	=	test.c lst_func.c
RM        =    rm -f
CC        =    cc
CFLAGS    =     -g #-Wall -Wextra -Werror -g
NAME    =    push_swap

all: $(NAME)

$(NAME):
	$(MAKE) all -C ./libft
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) ./libft/libft.a

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
    
re: fclean all

test: $(NAME)
	./push_swap 1 12 4 8 6 34

# val: all
# 	valgrind --leak-check=full \
# 		--show-leak-kinds=all \
# 		--track-origins=yes \
# 		--verbose \
# 		--log-file=valgrind-out.txt \
# 		./so_long maps/map.ber
    
.PHONY: all clean fclean re so_long test val