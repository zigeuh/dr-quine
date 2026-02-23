#include <stdio.h>
#include <fcntl.h>

#define START int main() {
#define STR ("#include <stdio.h>%c#include <fcntl.h>%c%c#define START int main() {%c#define STR (%c%s%c)%c#define END return 0; }%c%cSTART%c%cint fd = open(%cGrace_kid.c%c, O_CREAT | O_TRUNC | O_WRONLY, 0644);%c%cdprintf(fd, STR, 10, 10, 10, 10, 34, STR, 34, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10);%cEND")
#define END return 0; }

START
	int fd = open("Grace_kid.c", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dprintf(fd, STR, 10, 10, 10, 10, 34, STR, 34, 10, 10, 10, 10, 9, 34, 34, 10, 9, 10);
END