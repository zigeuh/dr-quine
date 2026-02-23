#include <stdio.h>
/*This is a comment outside of the program*/
int if_one() {int c = 1; if(c == 1) return 1; return 0;}
int main() {/*this is a comment*/char *str="#include <stdio.h>%c/*This is a comment outside of the program*/%cint if_one() {int c = 1; if(c == 1) return 1; return 0;}%cint main() {/*this is a comment*/char *str=%c%s%c; if_one(); printf(str, 10, 10, 10, 34, str, 34);}"; if_one(); printf(str, 10, 10, 10, 34, str, 34);}