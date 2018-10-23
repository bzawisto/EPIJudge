#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {
  if(x <= 0) return x == 0;

  int reversed = 0;
  int tmpX = x;
  while(tmpX) {
    reversed *= 10;
    reversed += tmpX % 10;
    tmpX /= 10;
  }
  return reversed == x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
