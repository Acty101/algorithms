// PROBLEM:
// Given 2 arrays representing stock price and profit, i.e. A1[i] and A2[i] are
// the price and profit of stock i, and a price range return the top 3 best
// performing stocks (highest profit) such that the stocks satisfies 2
// conditions
// 1. sum of price < price range
// 2. the items are of increasing price in its original position, i.e. if item 1
// is position i, item 2 is position j, then A1[i] < A1[j]

#include <iostream>
#include <vector>
using std::cout;
using std::max;
using std::vector;

struct Stock {
  uint32_t price;
  uint32_t profit;
};

// UNSOLVED
class BuyAndSellStock {
  vector<Stock> stocks;

 public:
  BuyAndSellStock(vector<uint32_t> price, vector<uint32_t> profit) {
    auto it1 = profit.begin();
    stocks.reserve(price.size());
    for (auto it = price.begin(); it != price.end(); ++it) {
      stocks.push_back({*it, *it1++});
    }
  };

  vector<Stock> getTop3(uint32_t budget) {
    vector<vector<vector<uint32_t>>> DP;
    DP.resize(4, vector<vector<uint32_t>>(stocks.size() + 1,
                                          vector<uint32_t>(budget + 1, 0)));
    // for (size_t i = 1; i < DP.size(); ++i) {
      int i = 1;
      for (size_t j = 1; j < DP[i].size(); ++j) {
        const Stock& stock = stocks[j - 1];
        for (size_t k = 1; k < DP[i][j].size(); ++k) {
          if (k >= stock.price) {
            DP[i][j][k] = max(DP[i][j - 1][k], // don't include item
                              DP[i][j - 1][k - stock.price] + stock.profit); // include item
          } else {
            DP[i][j] = DP[i - 1][j];
          }
        }
      }
    //}
    for(size_t i = 0; i < DP[1].size(); ++i){
      for(auto j:DP[1][i]){
        cout << j << ' ';
      }
      cout << '\n';
    }

    return {{0, 0}};
  }
};

int main() {
  vector<uint32_t> prices = {4, 6, 3, 2, 1, 7, 8, 2};
  vector<uint32_t> profits = {2, 5, 3, 6, 4, 8, 1, 9};
  BuyAndSellStock result(prices, profits);
  vector<Stock> stocks = result.getTop3(10);
  for (auto s : stocks) {
    cout << s.price << ' ' << s.profit << '\n';
  }
}