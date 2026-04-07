// gcc chal.c -o chal -fno-stack-protector -no-pie

#include <stdlib.h>
#include <stdio.h>

char* gets(char* s);

void win() {
	puts("RVCTF{c0ngr4ts_y0u_buff3r_0v3rfl0w3d!}");
	exit(0);
}

void vuln() {
    char buffer[100];
    int canary = 0xbeef;
    printf("input: ");
    gets(buffer);

    if (canary != 0xbeef) {
        puts("stack smashing detected!");
        exit(1);
    }
    puts("canary intact, but did you overflow?");
}

int main() {
    setbuf(stdout, NULL);
    printf("i'm feeling nice, here's an address: %p\n", win);
    vuln();
    puts("too bad no flag for you :(");
    return 0;
}