#include <iostream>
#include <algorithm>
using namespace std;
void SelectionSort(int (&ia)[], int n) {
  int min = 0;
  for (int i = 0; i < n - 1; ++i) {
    min = i;
    for (int j = i + 1; j < n; ++j) {
      if (ia[j] < ia[min])
        min = j;
    }
    swap(ia[i], ia[min]);
  }
}

void BubbleSort(int (ia)[], int n) {
  while (--n) {
    for (int i = 0; i < n; ++i) {
      if (ia[i] > ia [i + 1])
        swap(ia[i], ia[i + 1]);
    }
  }
}

int main() {
  int ia[4] = {10, 9, 8, 7};
  BubbleSort(ia, 4);
  for (int i = 0; i < 4; ++i) {
    cout << ia[i] << " ";
  }
}