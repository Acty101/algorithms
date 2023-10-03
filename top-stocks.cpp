// PROBLEM:
// Given 2 arrays representing stock price and profit, i.e. A1[i] and A2[i] are
// the price and profit of stock i, return the top 3 best performing stocks
// (highest profit) such that the stocks satisfies 2 conditions
// 1. sum of 3 stock prices <= some given price range
// 2. the items are of increasing price in its original position, i.e. if item 1
// is position i, item 2 is position j, then A1[i] < A1[j]

// return an empty array if no such 3 stocks are possible

#include <iostream>
#include <vector>
using std::cout;
using std::max;
using std::vector;

struct Stock {
  uint32_t price;
  uint32_t profit;
};


class TopStocks {
  vector<Stock> stocks;

 public:
  TopStocks(vector<uint32_t> price, vector<uint32_t> profit) {
    auto it1 = profit.begin();
    stocks.reserve(price.size());
    for (auto it = price.begin(); it != price.end(); ++it) {
      stocks.push_back({*it, *it1++});
    }
  };

  vector<Stock> getTop3(uint32_t budget) {
    vector<Stock> result(3);
    for(size_t i = 0; i < stocks.size(); ++i){

    }


    return {};
  }
};

int main() {
  vector<uint32_t> prices = {4, 6, 3, 2, 1, 7, 8, 2};
  vector<uint32_t> profits = {2, 5, 3, 6, 4, 8, 1, 9};
  TopStocks result(prices, profits);
  vector<Stock> stocks = result.getTop3(10);
  for (auto s : stocks) {
    cout << s.price << ' ' << s.profit << '\n';
  }
}