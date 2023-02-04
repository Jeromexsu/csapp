#include <stdio.h>
typedef unsigned char* byte_pointer;
void show_bytes(byte_pointer ptr, size_t size);
int main() {
    short sx = -15314;
    printf("sx = %d\n", sx);
    show_bytes((byte_pointer)&sx,sizeof(short));

    unsigned int x = sx;
    printf("x = %d\n", x);
    show_bytes((byte_pointer)&x,sizeof(unsigned int));

}

void show_bytes(byte_pointer ptr, size_t size) {
    int i;
    printf("address\t\tvalue\n");
    for(i=0; i<size; i++) {
        printf("%p\t%.2x\n",ptr+i,*(ptr+i));
    }
}

