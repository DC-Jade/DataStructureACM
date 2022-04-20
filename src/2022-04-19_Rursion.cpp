#include <iostream>
//#include <algorithm>
using std::cin;
using std::cout;

#define N 1000000
void AssignIntArray(int (&ia)[N], const int &n, const int &base) {
  for (int i = base; i < n + base; ++i)
    std::cin >> ia[i];
}

void TraverseIntArray(const int (&ia)[N], const int &n,
  const int &base) {
  // traverse and print
  for (int i = base; i < n + base; ++i)
    std::cout << ia[i] << " ";
  std::cout << std::endl;
}

void test1() {
  // input: 
  // n - length of int array, 1-base
  // m - search times
  // val - target 
  // tmp - pointer of lower_bound return
  // output:
  // first appear index or -1, sepearted by new line
  // intialize
  int n = 0;
  int m = 0;
  int val = 0;
  int ia[N] = {0};
  int base = 1;
  int *tmp;  
  std::cin >> n;
  std::cin >> m;
  AssignIntArray(ia, n, base);
  // TraverseIntArray(ia, n, base);

  while (m--) {
    std::cin >> val;
    tmp = std::lower_bound(ia, base + ia + n, val);
    if ((*tmp) == val) std::cout << tmp - ia << std::endl;
    else std::cout << -1 << std::endl;
  }
}

// recursive 
void test2() {
  int n = 0;
  int ia[N] = {0};
  std::cin >> n;
  ia[1] = 1;
  ia[2] = 1;
  for (int i = 3; i <= n; ++i) {
    ia[i] = ia[i - 1] + ia[i - 2];
  }
  std::cout << ia[n] << std::endl;
}

void Fibo() {
  int n = 0;
  scanf("%d", &n);
  int ia[N] = {0};
  ia[1] = 1;
  ia[2] = 1;
  for (int i = 3; i <= n; ++i) {
    ia[i] = ia[i - 1] + ia[i - 2];
  }
  printf("%d\n", ia[n]);
}

void YangHui() {
  int ia[100][100];
  int n = 0;
  scanf("%d", &n);
  // assign zero column
  for (int i = 0; i < n; ++i) {
    ia[i][0] = 1;
    ia[i][i] = 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < i; ++j) {
      ia[i][j] = ia[i - 1][j - 1] + ia[i - 1][j];
    }
    
    // print
    for (int j = 0; j <= i; ++j)
      printf("%d ", ia[i][j]);
    printf("\n");
  }
}

int main() {
  // test1();
  // test2();
  // Fibo();
  YangHui();
  return 0;
}