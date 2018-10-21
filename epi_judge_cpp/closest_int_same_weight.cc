#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  int bits = sizeof(x) * 8;
  for(int i = 1; i < bits; ++i) {
    if(((x >> i) & 0x1) != ((x >> (i -1)) & 0x1)) {
      unsigned long long mask = (1L << i) | (1L << (i - 1));
      x ^= mask;
      return x;
    }
  }
  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
