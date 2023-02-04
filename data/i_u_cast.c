#include <stdio.h>

typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer ptr, size_t size);

int main() {
    short int v = -12345;
    unsigned short int uv = (unsigned short int) v;
    printf("%d\n",v);
    show_bytes((byte_pointer)&v,sizeof(short));
    printf("%d\n",uv);
    show_bytes((byte_pointer)&uv,sizeof(unsigned short));
}

void show_bytes(byte_pointer ptr, size_t size) {
    int i;
    printf("address\t\tvalue\n");
    for(i=0; i<size; i++) {
        printf("%p\t%.2x\n",ptr+i,*(ptr+i));
    }
}