#include <stdio.h>
#include <fcntl.h>

#define FILENAME ("Grace_kid.c")
#define FT() int main(){int fd = open(FILENAME, O_CREAT | O_TRUNC | O_WRONLY, 0644);dprintf(fd, STR, STR, 10, 34);}
#define STR ("#include <stdio.h>%2$c#include <fcntl.h>%2$c%2$c#define FILENAME (%3$cGrace_kid.c%3$c)%2$c#define FT() int main(){int fd = open(FILENAME, O_CREAT | O_TRUNC | O_WRONLY, 0644);dprintf(fd, STR, STR, 10, 34);}%2$c#define STR (%3$c%1$s%3$c)%2$c%2$cFT()")

FT()