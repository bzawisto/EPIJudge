#include "test_framework/generic_test.h"
int Divide(int x, int y) {

  int power = 31;
  int result = 0;
  long long maxY = static_cast<long long>(y) << power;

  while(x >= y) {
    while(maxY > x) {
      maxY >>= 1;
      --power;
    }

    result += 1 << power;
    x -= maxY;
  }

  return result; 
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
