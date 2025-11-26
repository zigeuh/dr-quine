#include <stdio.h>
int main() {char *str="#include <stdio.h>%cint main() {char *str=%c%s%c; printf(str, 10, 34, str, 34);}"; printf(str, 10, 34, str, 34);}