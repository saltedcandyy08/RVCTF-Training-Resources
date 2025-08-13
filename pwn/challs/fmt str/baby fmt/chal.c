//  gcc -o chal chal.c -fno-pie -no-pie -fstack-protector

#include <stdlib.h>
#include <stdio.h>

void win() {
    puts("RVCTF{f0rm4t_str1ng5_w4snt_th4t_h4rd_w4s_1t?}");
    exit(0);
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
