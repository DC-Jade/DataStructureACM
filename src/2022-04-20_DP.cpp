#include <stdio.h>
#include <algorithm>

#define N 1000

void Initialize(int (&ia)[N][N], int &n) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      scanf("%d", &ia[i][j]);
    }
  }
}

void PrintIntArray(const int (&ia)[N][N], const int &n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j)
      printf("%d ", ia[i][j]);
  printf("\n");
  }
}

int DP(int (&ia)[N][N], int (&sa)[N][N], const int &n) {
  sa[0][0] = ia[0][0];
  // printf("%d\n", sa[0][0]);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) sa[i][j] = sa[i - 1][j] + ia[i][j];
      else if (j == i) sa[i][j] = sa[i - 1][j - 1] + ia[i][j];
      else sa[i][j] = std::max(sa[i - 1][j - 1], sa[i - 1][j]) + ia[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = std::max(ans, sa[n - 1][i]);
  return ans;
}

void test1() {
  int ia[N][N];
  int sa[N][N];
  int n;
  Initialize(ia, n);
  // PrintIntArray(ia, n);
  // Initialization(ia, sa, n);
  int res;
  res = DP(ia, sa, n);
  // PrintIntArray(sa, n);
  printf("%d\n", res);
}

bool IsSorted(const int (&ia)[N], const int &n) {
  for (int i = 1; i < n; ++i) {
    if (ia[i - 1] > ia[i]) return false;
  }
  return true;
}
/*
bool HaveSorted(const int (&ia)[N], int (&tmp_ia)[N], const int &n)  {
  int tmp_len = n;
  while (tmp_len--) {
    for (int i = 0; i < n && i != tmp_len; ++i) {
      tmp_ia[i] = ia[i]; 
    }
    if (IsSorted(tmp_ia, n - 1)) return true;
  }
  return false;
}


int LongestOrderedSequence(int (&ia)[N], int (&res_seq)[N], int &n) {
  InitializeIntArray(ia, n);
  while (n > 1 && !IsSorted(ia, n)) {
    if (HaveSorted(ia, res_seq, n)) return --n;
    --n;
  }
  return n;
}
*/

void InitializeIntArray(int (&ia)[N], int &n) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &ia[i]);
}

void test2() {
  int ia[N]; 
  int sa[N];
  int n;
  int res = 0;
  InitializeIntArray(ia, n);
  for (int i = 0; i < n; ++i) {
    sa[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (ia[j] < ia[i])
        sa[i] = std::max(sa[j] + 1, sa[i]);
    }
    res = std::max(res, sa[i]);
  }
  printf("%d\n", res);
}
int main() {
  // test1();
  test2();
  return 0;
}