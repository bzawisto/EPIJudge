#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::min;
using std::max;

double BuyAndSellStockOnce(const vector<double>& prices) {
  double maxProfit = 0.0;
  double minVal = std::numeric_limits<double>::max();
  for(auto price : prices) {
    minVal = min(price, minVal);
    maxProfit = max(maxProfit, price - minVal);
  }
  return maxProfit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
