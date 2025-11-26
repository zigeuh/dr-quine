#include <stdio.h>
#include <fcntl.h>

#define START int main() {
#define END return 0; }

START
	char *str ="#include <stdio.h>%c#include <fcntl.h>%c%c#define START int main() {%c#define END return 0; }%c%cSTART%c%cchar *str =%c%s%c;%c%cint fd = open(%cGrace_kid.c%c, O_CREAT | O_TRUNC | O_WRONLY, 0644);%c%cdprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 9, 34, str, 34, 10, 9, 34, 34, 10, 9, 10);%cEND";
	int fd = open("Grace_kid.c", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 9, 34, str, 34, 10, 9, 34, 34, 10, 9, 10);
END