#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long fibonacci_fast(long long n) {
    long long f[n+2]={0};
    f[0] = 0;
    f[1] = 1;
    for (long long i = 2; i < n+3; ++i)
    {
        f[i] = f[i-1]+f[i-2];
    }

    return (f[n+1]%10)*(f[n]%10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n%60)%10<<'\n';
    //std::cout<< fibonacci_sum_squares_naive(n)<<"\n";
}
