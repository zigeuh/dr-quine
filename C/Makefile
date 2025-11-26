all:
	clang -Wall -Wextra -Werror -o Colleen Colleen.c; ./Colleen > tmp_Colleen ; diff tmp_Colleen Colleen.c

fclean:
	rm -rf Colleen tmp_Colleen