#include <stdio.h>
/*This is a comment outside of the program*/
int if_one() {int c = 1; if(c == 1) return 1; return 0;}
int main() {
	/*this is a comment*/
	char *str="#include <stdio.h>%2$c/*This is a comment outside of the program*/%2$cint if_one() {int c = 1; if(c == 1) return 1; return 0;}%2$cint main() {%2$c%3$c/*this is a comment*/%2$c%3$cchar *str=%4$c%s%4$c;%2$c%3$cif_one();%2$c%3$cprintf(str, str, 10, 9, 34);%2$c}";
	if_one();
	printf(str, str, 10, 9, 34);
}