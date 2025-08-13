//  gcc -o chal chal.c -fno-pie -no-pie -fstack-protector

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void win() {
    execve("/bin/sh", NULL, NULL);
}

void vuln() {
    char buffer[64];
    printf("input: ");
    fgets(buffer, sizeof(buffer)-1, stdin);

    printf("you entered: ");
    printf(buffer);
    puts(NULL);
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    vuln();
    return 0;
}
