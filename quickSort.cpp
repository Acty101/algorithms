#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename COMP = less<T>>
class QuickSort {
 private:
  vector<T> data;
  COMP comparator;

  void sortHelper(int startIndex, int endIndex) {
    if (startIndex < endIndex) {
      // choose last element as pivot
      const int& pivotIndex = endIndex;
      for (int i = startIndex; i < endIndex; ++i) {
        if (this->comparator(data[i], data[pivotIndex])) {
          swap(data[i], data[startIndex++]);
        }
      }
      // bring pivot to its right position
      swap(data[pivotIndex], data[startIndex]);
      // recursively sort the smaller 2 sides
      sortHelper(0, startIndex - 1);
      sortHelper(startIndex + 1, endIndex);
    }
  }

 public:
  QuickSort(const vector<T>& data, const COMP& comp)
      : data{data}, comparator{comp} {}

  void sort() { sortHelper(0, static_cast<int>(data.size()) - 1); }

  void print() {
    for (auto it = data.begin(); it != data.end(); ++it) {
      cout << *it << ' ';
    }
    cout << endl;
  }
};

int main() {
  vector<int> temp = {3, 2, 1, 5, 7, 12, 3, 1, 2};
  less<int> comp;
  QuickSort<int> sorter(temp, comp);
  sorter.sort();
  sorter.print();
}