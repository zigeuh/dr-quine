#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int count = 5;
	if (count <= 0) return (0);
	char *str = "#include <stdio.h>%2$c#include <stdlib.h>%2$c#include <fcntl.h>%2$c#include <string.h>%2$c%2$cint main() {%2$c%3$cint count = %5$d;%2$c%3$cif (count <= 0) return (0);%2$c%3$cchar *str = %4$c%1$s%4$c;%2$c%3$cchar name[9] = %4$cSully5.c%4$c;%2$c%3$cif (strstr(__FILE__, %4$cSully.c%4$c) == NULL)%2$c%3$c%3$ccount--;%2$c%3$cname[5] = count + 48;%2$c%3$cint fd = open(name, O_CREAT | O_WRONLY, 0644); name[6] = 0;%2$c%3$cdprintf(fd, str, str, 10, 9, 34, count);%2$c%3$cif (count <= 0) return (0);%2$c%3$cchar command[256]; snprintf(command, sizeof(command), %4$cclang -Wall -Wextra -Werror -o %%1$s %%1$s.c ; ./%%1$s%4$c, name);%2$c%3$cint ret = system(command); return (ret);%2$c}";
	char name[9] = "Sully5.c";
	if (strstr(__FILE__, "Sully.c") == NULL)
		count--;
	name[5] = count + 48;
	int fd = open(name, O_CREAT | O_WRONLY, 0644); name[6] = 0;
	dprintf(fd, str, str, 10, 9, 34, count);
	if (count <= 0) return (0);
	char command[256]; snprintf(command, sizeof(command), "clang -Wall -Wextra -Werror -o %1$s %1$s.c ; ./%1$s", name);
	int ret = system(command); return (ret);
}