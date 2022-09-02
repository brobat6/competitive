int StreetPlanning(int input1) {
    int fib[input1 + 1];
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i <= input1; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[input1] * fib[input1];
}