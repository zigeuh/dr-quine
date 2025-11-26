all:
	clang -Wall -Wextra -Werror -o Colleen Colleen.c; ./Colleen > tmp_Colleen ; diff tmp_Colleen Colleen.c
	clang -Wall -Wextra -Werror -o Grace Grace.c; ./Grace ; diff Grace.c Grace_kid.c

fclean:
	rm -rf Colleen tmp_Colleen
	rm -rf Grace Grace_kid.c