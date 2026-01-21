#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void e() {
	_exit(0);
}

int main() {
	char local[0x100];
	memset(local, 0, sizeof(local));
	void (*func)() = e;
	read(0, local, 0x110);
	__asm__("jmp *%0" :: "r"(func));
	return 0;
}
