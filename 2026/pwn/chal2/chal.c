// gcc chal.c -masm=intel -no-pie -fno-stack-protector -o chal
#include <stdio.h>
asm("pop rdi; ret; pop rsi; ret;"); //ignore this
int win(int arg1, int arg2){
    if (arg1 == 0x69696969 && arg2 == 0x13371337){
        system("cat flag.txt");
    } else {
        puts("Incorrect arguments!");
    }
    _exit(0);
}
int main(){
    char buf[10];
    printf("Please enter something: ");
    gets(buf);
}