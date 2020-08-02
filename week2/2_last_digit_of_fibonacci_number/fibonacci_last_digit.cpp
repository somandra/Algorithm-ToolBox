#include <iostream>

long long f[10000001]={0};
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_fast(int n) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n+1; ++i)
    {
        f[i] = (f[i-1]+f[i-2])%10;
    }

    return f[n]%10;
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    //std::cout << c << '\n';
    std::cout<< fibonacci_fast(n)<<'\n';
    }
