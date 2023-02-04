long add(long *xp, long *yp) {
    return (*xp)+(*yp);
} 
long caller() {
    long arg1 = 534;
    long arg2 = 1057;
    long sum = add(&arg1,&arg2);
    long diff = arg1 - arg2;
    return sum*diff;
}