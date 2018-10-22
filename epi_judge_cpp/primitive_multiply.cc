#include "test_framework/generic_test.h"

unsigned long long addSum(unsigned long long x, unsigned long long y) {
  unsigned long long tmpX = x;
  unsigned long long tmpY = y;
  unsigned long long sum = 0;
  unsigned long long carry = 0;
  unsigned long long  k = 1;
  while(tmpX || tmpY) {
    unsigned long long xk = x & k, yk = y & k;
    unsigned long long tmpCarry = (xk & yk) | (xk & carry) | (yk & carry);
    unsigned long long digit = xk ^ yk ^ carry;
    sum |= digit;
    carry = tmpCarry << 1;
    tmpX >>= 1;
    tmpY >>= 1;
    k <<= 1;
  }
  return sum | carry;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long ans = 0;
  while(x) {
    if(x & 1) {
      ans = addSum(y, ans);
    }
    x >>= 1;
    y <<= 1;
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
