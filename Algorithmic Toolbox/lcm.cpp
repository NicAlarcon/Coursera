#include <iostream>

int gcd_fast(int a, int b) {
  if (b == 0)
    return a;
  int c = a%b;
  return gcd_fast(b,c);
}

long long lcm_fast(int a, int b){
  long long c = (long long) a*b / gcd_fast(a,b);
  return c;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  long long c = lcm_fast(a, b);
  std::cout << c << std::endl;
  return 0;
}
