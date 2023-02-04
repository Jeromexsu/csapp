#include<stdio.h>

void inplace_swap(int* x, int* y);

int main() {
    int a = 1;
    int b = 1;
    printf("a=%d\tb=%d\n",a,b);
    inplace_swap(&a,&a);
    printf("a=%d\tb=%d\n",a,b);
}


void inplace_swap(int* x, int* y) {
    *y = *x^*y;
    *x = *x^*y;
    *y = *x^*y;
}