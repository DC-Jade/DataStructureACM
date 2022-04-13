#include <iostream>
#include <algorithm>
using namespace std;

// pay
void Pay() {
  int a, b, c, d, n, sum, count;
  cin >> a >> b >> c >> d >> n;
  sum = 0;
  count = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int m = 0; m <= c; ++m) {
        for (int k = 0; k <= d; ++k) {
          sum = i + 3 * j + 5 * m + 10 * k;
          if (sum == n)
            ++count;
        }
      }
    }
  }
  if (count == 0)
    cout << "no";
  else
    cout << count;
}

// daffodils number
void FindDafflodils() {
  int m, n;
  cin >> m >> n;

  // check input legal
  if (100 <= m && m <= n && n <= 999) {}
  else
    cout << "m & n illegal";

  //
  int hundred, ten, single, sum;
  int count = 0;
  for (int i = m; i <= n; ++i) {
    hundred = i / 100;
    ten = (i / 10) % 10;
    single = i % 10;
    sum = hundred * hundred * hundred + ten * ten * ten +
          single * single * single;
    if (sum == i) {
      cout << i << " ";
      ++count;  
    }
  }
  if (count == 0)
    cout << "no";
}  // function FindDafflodils

void EnumSubset() {
  int n;
  scanf("%d", &n);  // 集合大小，也就是01比特串的长度
  // n = 3;
  int tot = 1 << n; // 枚举数字代替01比特串，范围为0到2^n - 1
  int ans = 0;
  for (int num = 0; num < tot; ++num) { // 枚举每个代表01比特串的数字
    long long sum = 0;
    for (int i = 0; i < n; ++i) // 枚举01比特串的每一位
      if ((num >> i) & 1) {                 // 检查第j位是否为1，注意这里是从0开始枚举
        sum += (i + 1); // 如果该位是1，就把对应的数字加到求和的变量里
      }
    if (sum % 3 == 0)
      ++ans; // 如果满足题目要求（3的倍数），计入答案
  }
  printf("%d\n", ans);
}

// zhu xin suan
const int N = 100;
int n;
int ia[N];
bool CheckZhuXin(int i) {
  for (int j = 0; j < n; ++j) {
    for (int k = j + 1; k < n; ++k) {
      if (ia[j] + ia[k] == ia[i])
        return true;
    }
  }
  return false;
}

void ZhuXin() {
  cin >> n;
  int count = 0;
  // save input in ia
  for (int i = 0; i < n; ++i) {
    cin >> ia[i];
  }
  for (int i = 0; i < n; ++i) {
    if (CheckZhuXin(i)) {
      ++count;
    }
  }
  cout << count;
}

// a:b:c
int one = 0;
int two = 0;
int three = 0;
bool CheckPremutaion(int ia[], int a, int b, int c) {
  one = ia[0] * 100 + ia[1] * 10 + ia[2];
  two = ia[3] * 100 + ia[4] * 10 + ia[5];
  three = ia[6] * 100 + ia[7] * 10 + ia[8];
  if ((a * two == b * one) && (a * three == c * one))
    return true;
  else
    return false;
}

void Permutation(){
  int a = 0, b = 0, c = 0;
  cin >> a >> b >> c;
  int total = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
  int ia[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int count = 0;
  for (int i = 0; i < total; ++i) {
    if (CheckPremutaion(ia, a, b, c)) {
      ++count;
      cout << one << " " << two << " " << three << "\n";
    }

    // next permutaion
    if (next_permutation(ia, ia + 9))
      continue;
    else if (count != 0)
      break;
    else
      cout << "No!!!";
  }
}

int main() {
  // Pay();
  // FindDafflodils();
  // ZhuXin();
  Permutation();
}