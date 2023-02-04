// function determines whether the addition will cause overflow

#include <stdio.h>
#include <stdlib.h>

int overflow_unsigned(unsigned ux, unsigned uy);
int main(int argc, char* argv[]) {
    unsigned ux = (unsigned) atoi(argv[1]);
    unsigned uy = (unsigned) atoi(argv[2]);
    if(overflow_unsigned(ux,uy))
        printf("ux(%u) + uy(%u) will cause overflow",ux,uy);
    else 
        printf("ux(%u) + uy(%u) will not cause overflow",ux,uy);
}

int overflow_unsigned(unsigned ux, unsigned uy) {
    unsigned s = ux+uy;
    return s < ux;
}