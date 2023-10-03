#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct Item {
  uint32_t weight;
  uint32_t value;
};

class Solution {
  vector<Item> items;

 public:
  Solution(const vector<uint32_t>& weights, const vector<uint32_t> values) {
    for (size_t i = 0; i < weights.size(); ++i) {
      Item item = {weights[i], values[i]};
      items.push_back(item);
    }
  }

  void print(const vector<vector<uint32_t>>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
      for (size_t j = 0; j < vec[i].size(); ++j) {
        cout << vec[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  // O(n^2) runtime, O(n^2) space
  uint32_t findMaxValue(uint32_t capacity) {
    vector<vector<uint32_t>> DP;
    // init DP table to 0-capacity on x axis, 0 - i items on y axis
    DP.resize(items.size() + 1,
              vector<uint32_t>(static_cast<size_t>(capacity + 1), 0));
    for (size_t i = 1; i < DP.size(); ++i) {
      const Item& currentItem = items[i - 1];
      for (size_t j = 1; j < DP[i].size(); ++j) {
        // start from 1 since 0th row and col always 0 -> no item or no capcity
        // to fit
        if (j < currentItem.weight) {
          // no capcity to fit
          DP[i][j] = DP[i - 1][j];
        } else {
          DP[i][j] = std::max(DP[i - 1][j], DP[i - 1][j - currentItem.weight] +
                                                currentItem.value);
        }
      }
    }
    print(DP);  // to check solution

    return DP[items.size()][capacity];
  }

  // O(n^2) runtime, O(n) space
  uint32_t findMaxValueOptimized(uint32_t capacity) {
    vector<uint32_t> DP_1D(capacity + 1, 0);
    for (size_t i = 1; i < items.size() + 1; ++i) {
      const Item& currentItem = items[i - 1];
      for (uint32_t j = capacity; j > 0; --j) {
        if (j >= currentItem.weight) {
          DP_1D[j] = std::max(
              DP_1D[j], DP_1D[j - currentItem.weight] + currentItem.value);
        }
      }
    }
    return DP_1D[capacity];
  }
};

int main() {
  vector<uint32_t> weights = {3, 2, 1, 4};
  vector<uint32_t> values = {1, 4, 2, 6};
  Solution s(weights, values);
  cout << s.findMaxValueOptimized(9);
}