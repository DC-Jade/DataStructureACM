#include <stdio.h>
#include <stack>
#include <iostream>

#define N 1000

void Input(int (&ia)[N], int &len) {
  scanf("%d", &len);
  for (int i = 0; i < len; ++i)
    scanf("%d", &ia[i]);
}
int MaxSubsequence(const int (&ia)[N], const int &len) {
  int this_sum;
  int max_sum = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i; j < len; ++j) {
      this_sum = 0;
      for (int k = i; k <= j; ++k) {
        this_sum += ia[k];
      }
      max_sum = std::max(max_sum, this_sum);
    }
  }
  // printf("%d\n", max_sum);
  return max_sum;
}

/*
void ReversedPolishNotation() {
  std::stack<int> stack;
  // input
  int tmp;
  while (std::cin >> tmp) {
    if (isnumber(tmp))
      stack.push(tmp);
  }
}
*/

void test1() {
  int ia[N];
  int len;
  Input(ia, len);
  printf("%d", MaxSubsequence(ia, len)); 
}


int main() {
  test1();
}