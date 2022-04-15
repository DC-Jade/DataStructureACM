#include <iostream>
using namespace std;
#define N 10000

int BinSearch(const int (&ia)[N], int n, int x) {
  // ia: sorted int array
  // n:  length of ia
  // x:  target int
  int rhs = n;
  int lhs = 0;
  int mid = lhs + ((rhs - lhs) >> 1);

  while (rhs > lhs) {
    mid = lhs + ((rhs - lhs) >> 1);
    if (x == ia[mid]) 
      return mid;
    else if (x < ia[mid])
      rhs = mid;
    else lhs = mid + 1;
  }
  // if (ia[lhs] == x) return lhs;
  return -1;
}

int main() {
    int n;
    int ia[N];
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i)
      cin >> ia[i];
    cin >> x;
    int index = BinSearch(ia, n, x) + 1;
    (index != 0) ? cout << index  : cout << "not find";
    return 0;
}