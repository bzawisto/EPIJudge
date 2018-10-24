#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::abs;

vector<int> Multiply(vector<int> num1, vector<int> num2) {
  int sign = (num1.front() < 0 ^ num2.front() < 0) ? -1 : 1;
  num1.front() = abs(num1.front());
  num2.front() = abs(num2.front());
  
  vector<int> ret(num1.size() + num2.size(), 0);
  for(int i = num1.size() - 1; i >= 0; --i) {
    for(int j = num2.size() - 1; j >= 0; --j) {
      ret[i+j+1] += num1[i] * num2[j];
      ret[i+j] += ret[i+j+1] / 10;
      ret[i+j+1] %= 10;
    }
  }
  
  ret = {std::find_if_not(ret.begin(), ret.end(), [](int a) { return a == 0;}), ret.end()};

  if(ret.empty()) return {0};

  ret.front() *= sign;
  return ret;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
