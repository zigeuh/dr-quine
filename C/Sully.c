#include <stdio.h>
#include <fcntl.h>

int main() {
	int count = 5;
	char *str = "#include <stdio.h>%c#include <fcntl.h>%c%cint main() {%c%cint count = %d;%c%cchar *str = %c%s%c;%c%cchar name[9] = %cSully5.c%c;%c%cname[5] = count + 48;%c%cint fd = open(name, O_CREAT | O_WRONLY, 0644);%c%cdprintf(fd, str, 10, 10, 10, 10, 9, count - 1, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10);%c}";
	char name[9] = "Sully5.c";
	name[5] = count + 48;
	int fd = open(name, O_CREAT | O_WRONLY, 0644);
	dprintf(fd, str, 10, 10, 10, 10, 9, count - 1, 10, 9, 34, str, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10, 9, 10);
}