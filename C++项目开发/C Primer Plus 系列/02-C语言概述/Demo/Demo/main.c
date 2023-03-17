#include <stdio.h>

// 函数的原型、声明
void butler();

int main() {

    /*
    int n;
    int n2;
    int n3;
    */

    // This program has several errors.
    /* This program has several errors. */
    int a = 1;

    printf("a = %d\n", a);

    a = 2;
    a = 3;
    a = 4;

    printf("I will summon the butler function.\n");

    // 函数的调用
    butler();

    printf("Yes. Bring me some tea and writeable DVDs.\n");

    return 0;
}

// 函数的实现
void butler() {
    printf("You rang, sir?\n");
}