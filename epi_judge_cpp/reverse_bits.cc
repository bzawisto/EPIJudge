#include "test_framework/generic_test.h"

void swapBits(unsigned long long& x, int i, int j) {
  if(((x >> i) & 0x1) != ((x >> j) & 0x1)) {
    unsigned long long mask = (1L << i) | (1L << j);
    x ^= mask;
  }
}
unsigned long long ReverseBits(unsigned long long x) {
  int bits = sizeof(x) * 8;
  for(int i = 0; i < bits / 2; ++i) {
    swapBits(x, i, bits - i - 1);
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
