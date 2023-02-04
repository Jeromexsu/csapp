#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer ptr, size_t size);

int main(int argc, char* argv[]) {
    char* a = "hello world\0";
    //a = atoi(argv[1]);
    printf("string a = %s\n-------\n",a);
    show_bytes((byte_pointer) a, strlen(a)+1);
}



void show_bytes(byte_pointer ptr, size_t size) {
    int i;
    printf("address\t\tvalue\n");
    for(i=0; i<size; i++) {
        printf("%p\t%.2x\n",ptr+i,*(ptr+i));
    }
}