#include <stdio.h>

void f1(void){
	printf("I am a function of f1.\n");    
}

int main(void){
    
    int num;
    num = 1;
    
    printf("I am blackcat. ");
    
    printf("I love C programming.\n");
    
    printf("My favorite num is %d because it is first.\n", num);
    
    f1();   // 函数调用
    
    // 单行注释
    
    /*
    	这是
           一个
              多行
                 注释
    */
    
    return 0;
}
