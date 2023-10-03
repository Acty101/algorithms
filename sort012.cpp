#include <iostream>
#include <vector>

using namespace std;

void sort0123(vector<int> &nums) {
  uint32_t index1 = 0, index2 = static_cast<uint32_t>(nums.size()) - 1,
           index3 = index2;
  for (size_t i = 0; i < nums.size(); ++i) {
    // either index1++, or index2/index3--
    if (nums[index1] == 0) {
      index1++;
    } else if (nums[index1] == 2) {
      swap(nums[index1], nums[index2]);
      if (index3 < index2) {
        swap(nums[index1], nums[index3]);
      }
      index2--;
      index3--;
    } else {
      swap(nums[index1], nums[index3--]);
    }
  }
}

int main() {
  vector<int> temp = {1, 1, 0, 1, 2, 2, 1, 2, 0, 1, 2, 0, 2, 1};
  sort0123(temp);
  for (auto i : temp) {
    cout << i << ' ';
  }
}