name:
	make -C ./libft
	gcc -fsanitize=address check_numbers.c -L ./libft -lft -o push_swap
	
run: name
	./push_swap 7 5 39 2 0 -7 -55

fclean:
	make -C ./libft fclean
	rm -rf push_swap