#include <iostream>
using std::swap;
#define N 300000

struct test {
  int num;
  char name[5];
  char s;
};

void InsertionSort(int (&ia)[N], int n) {
  int j = 0;
  int current = 0;
  for (int i = 1; i < n; ++i) {
    current = ia[i];
    for (j = i; (j > 0) && (ia[j - 1] > current); --j) {
      ia[j] = ia[j - 1];
    }
    ia[j] = current;
  }
}

/*
void Deduplicate(int (&ia)[N], int &n) {
  for (int i = 0; i < n - 1; ++i) {
    if (ia[i] == ia[i + 1]) {
      for (int j = i + 1; j < n - 1; ++j)
        ia[j] = ia[j + 1];
      --n;
    }
  }
}
*/

int Deduplicate(int (&ia)[N], int n) {
  int index = 0;
  for (int i = 0; i < n; ++i) {
    if (((i != n - 1) && (ia[i] != ia [i + 1])) || i == n - 1)
      ia[index++] = ia[i];
  }
  return index;
}


void QuickSort(int (&ia)[N], int lhs, int rhs) {
    int k = lhs - 1;
    int current = ia[rhs];
    for (int i = lhs; i < rhs; ++i) {
        // swap
        if (ia[i] < current)
            swap(ia[i], ia[++k]);
    }
    swap(ia[++k], ia[rhs]);
    if (lhs < k - 1)
        QuickSort(ia, lhs, k - 1);
    if (rhs > k + 1) 
        QuickSort(ia, k + 1, rhs);
}



int CountSort(int (&ia)[N], int (&res_a)[N][2], int n) {
  // int res_a[N][2];  // result array
  // std::cout << "initial n: " << n << std::endl;
  QuickSort(ia, 0, n - 1);
  // std::cout << "after QuickSort n: " << n << std::endl;
  // count recurrence
  int count = 0;
  int index = 0;
  for (int i = 0; i < n; ++i) {
    // std::cout << "hit for loop\n"
    //          << std::endl;
    if (i == 0 || ia[i] != ia[i - 1]) {
      count = 1;
      res_a[index][0] = ia[i];
      res_a[index][1] = count;
      ++index;
    //  std::cout << "hit if branch\n";
    } else {
      res_a[index - 1][1] = ++count;
    //  std::cout << "hit else branch\n";
    }
  }
  //return index - 1;
  // std::cout << "res_a index: " << index << std::endl;
  // std::cout << "n: " << n;
  return index;
}

int main () {
  int ia[N];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &ia[i]);
  // std::cout << n << std::endl;
  /*
  @ InsertionSort
  */
  /*
  // InsertionSort
  InsertionSort(ia, n);

  // deduplicate
  int len = Deduplicate(ia, n);

  // Print
  printf("%d\n", len);
  for (int i = 0; i < len; ++i)
    printf("%d ", ia[i]);
  */

  /*
  @ QuickSort
  */
  /*
  // QuickSort
  QuickSort(ia, 0, n - 1);
  // Print
  for (int i = 0; i < n; ++i)
    printf("%d ", ia[i]);
  printf("\n");
  */
  // CountSort
  int res_a[N][2] = {{0,0}};
  int len = CountSort(ia, res_a, n);
  // Print
  for (int i = 0; i < len; ++i)
    printf("%d %d\n", res_a[i][0], res_a[i][1]);
  test test1;
  std::cout << sizeof(test);
}