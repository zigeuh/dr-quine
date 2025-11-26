#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	int count = 5;
	char *str = "#include <stdio.h>%c#include <stdlib.h>%c#include <fcntl.h>%c%cint main() {%c%cint count = %d;%c%cchar *str = %c%s%c;%c%cchar name[9] = %cSully5.c%c; count--; name[5] = count + 48;%c%cint fd = open(name, O_CREAT | O_WRONLY, 0644);%c%cdprintf(fd, str, 10, 10, 10, 10, 10, 9, count, 10, 9, 34, str, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10);%c}";
	char name[9] = "Sully5.c"; count--; name[5] = count + 48;
	int fd = open(name, O_CREAT | O_WRONLY, 0644);
	name[6] = 0;
	dprintf(fd, str, 10, 10, 10, 10, 10, 9, count, 10, 9, 34, str, 34, 10, 9, 34, 34, 10, 9, 10, 9, 10);
	char command[256]; snprintf(command, sizeof(command), "clang -Wall -Wextra -Werror -o %s %s.c ; ./%s", name, name, name);
	int ret = system(command); return (ret);
}