int addcnt = 0;

void addvec(int *x, int *y, int*z, int n) {
    addcnt++;
    int i;
    for(i=0; i<n; i++) {
        z[i] = x[i] + y[i];
    }
}