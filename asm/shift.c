int shift(int x, int n) {
    x <<= 2;
    x >>= n;
    return x;
}