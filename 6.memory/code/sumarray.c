int sumarrayrows(int* a, int M, int N) {
    int i,j,sum = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum += *(a+N*i+j);
        }
    }
}

int sumarraycols(int* a, int M, int N) {
    int i,j,sum = 0;
    for (j = 0; j < N; i++) {
        for (i = 0; i < M; j++) {
            sum += *(a+N*i+j);
        }
    }
}