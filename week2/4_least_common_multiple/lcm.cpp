#include <iostream>

long long lcm_naive(long a, long b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(long long a,long long b){
  if (b==0)
  {
    return a;
  }
  return gcd(b,a%b);
}

long long lcm_optimized(long a, long b){
	return (a*b)/gcd(a,b);
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_optimized(a, b) << std::endl;
  return 0;
}
