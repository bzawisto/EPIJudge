#include <vector>
#include "test_framework/generic_test.h"
using std::vector;

vector<int> PlusOne(vector<int> A) {
  vector<int> retVal;
  int carry = 0;
  for(int i = A.size() - 1; i >= 0; --i) {
    int sum = A[i] + carry;
    if(i == A.size() - 1) sum++;
    retVal.push_back(sum % 10);
    carry = sum / 10;
  }
  if(carry) retVal.push_back(carry);
  std::reverse(retVal.begin(), retVal.end());
  return retVal;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
