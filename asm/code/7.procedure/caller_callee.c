long callee(long a) {
    return a+1;
}
long caller(long x, long y) {
    long u = callee(y);
    long v = callee(x);
    return u+v;
}