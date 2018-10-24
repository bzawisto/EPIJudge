#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
  if(prices.empty()) return 0.0;

  vector<double> profits(prices.size(), 0.0);
  double maxProfit = 0.0;
  double minVal = std::numeric_limits<double>::max();
  int i = 0;
  for(auto p : prices) {
    minVal = std::min(minVal, p);
    maxProfit = std::max(maxProfit, p - minVal);
    profits[i++] = maxProfit;
  }
  double maxPrice = std::numeric_limits<double>::min();

  for(i = prices.size() - 1; i > 0; --i) {
    maxPrice = std::max(maxPrice, prices[i]);
    maxProfit = std::max(maxProfit, maxPrice - prices[i] + profits[i-1]);
  }
  return maxProfit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
