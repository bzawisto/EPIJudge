#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::max;

bool CanReachEnd(const vector<int>& max_advance_steps) {
  if(max_advance_steps.empty()) return false;

  int currMax = max_advance_steps[0];

  for(int i = 1; i < max_advance_steps.size(); ++i) {
    if(!currMax) return false;
    currMax = max(currMax - 1, max_advance_steps[i]);
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
