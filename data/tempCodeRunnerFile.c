#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer ptr, size_t size);

int main(int argc, char* argv[]) {
    short a = (short)atoi(argv[1]);
    printf("short a = %s\n-------\n",a);
    show_bytes((byte_pointer) a, sizeof(short));
}

void show_bytes(byte_pointer ptr, size_t size) {
    int i;
    printf("address\t\tvalue\n");
    for(i=0; i<size; i++) {
        printf("%p\t%.2x\n",ptr+i,*(ptr+i));
    }
}