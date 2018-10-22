#include "test_framework/generic_test.h"
double powH(double x, int y) {
  if(y == 1) return x;
  if(y == 0) return 1.0;
  
  double tmp = powH(x, y / 2);
  tmp = tmp * tmp;
  if(y % 2) {
    tmp *= x;
  }
  return tmp;
}
double Power(double x, int y) {
  double val = powH(x, abs(y));
  if(y < 0) {
    return 1.0/val;
  }
  return val;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
