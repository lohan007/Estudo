#include <stdio.h> 

void soma(int* num, int a, int b){
    (*num) = a + b;
}

int main(){
    int num, a, b;

    a = 3;
    b = 5;

    soma(&num, a, b);
    printf("%d\n", num);

    return 0;
}