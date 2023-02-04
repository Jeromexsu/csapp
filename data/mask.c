#include <stdio.h>
//The least significant byte of x, with all other bits set to 0.
void mask1(int x);
// All but the least significant byte of x complemented, with the least signiﬁcant byte left unchanged.
void mask2(int x);
//The least significant byte set to all ones, and all other bytes of x left unchanged.
void mask3(int x);

int main() {
    int x = 0x87654321;
    mask1(x);
    mask2(x);
    mask3(x);
    return 0;
}

void mask1(int x) {
    int mask = 0xff;
    x = x & mask;
    printf("%x\n",x);

}

void mask2(int x) {
    int mask = ~ 0xff;
    x = x ^ mask;
    printf("%x\n",x);

}

void mask3(int x) {
    int mask = 0xff;
    x = x | 0xff;
    printf("%x\n",x);
}