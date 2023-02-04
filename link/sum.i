# 1 "sum.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 369 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "sum.c" 2
int sum(int* arr, int n) {
    int i , sum = 0;
    for (i = 0; i < n; i++)  {
        sum += arr[i];
    }
    return sum;
    
}
