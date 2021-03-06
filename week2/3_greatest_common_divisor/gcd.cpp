#include <iostream>

long long gcd_naive(long long a, long long b) {
  long long current_gcd = 1;
  for (long long d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_optimized(long long a,long long b){
  if (b==0)
  {
    return a;
  }
  return gcd_optimized(b,a%b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_optimized(a, b) << std::endl;
  return 0;
}
