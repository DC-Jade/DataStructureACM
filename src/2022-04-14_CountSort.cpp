#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <map>
using std::map;

#define N 200000
//#define K 1500000000
// void CountSort(const int (&ia)[N], int (&res_ia)[N], int n) {
void CountSort(const int (&ia)[N], int (&res_ia)[N], int n) {
  // res_ia[N] = {0};  // sorted array
  //  vector<int> cnt_ia;  // count vector, array too short, which is located in stack
  //  count map, save recurrence;
  // TODO: check i whether exist in ia
  

  map<int, int> count_map;
  for (int i = 0; i < N; ++i) {
    if (count_map.find(i) != count_map.end()) {
      ++count_map[i];
    } else {
      count_map.insert(std::pair<int, int>(i, 1));
    }
  }
  

  /*
  // count ia[i]
  for (int i = 0; i < K; ++i)
    cnt_ia.push_back(0);
  for (int i = 0; i < n; ++i) {
    ++cnt_ia[ia[i]];
  }
  */

  // save in res_ia
  for (int i = 0, j = 0; i < n; ++i) {
    //if (count_map.find(i) == count_map.end()) 
    //  continue;
    for (int k = 0;
      count_map.find(i) != count_map.end() && 
      k < count_map[i]; ++k) {
      // ia[i] refer to i's recurrence
      res_ia[j++] = i;
    }
  }
}

void PrintIntArray(const int (&ia)[N], int n) {
  for (int i = 0; i < n; ++i)
    std::cout << ia[i] << " ";
  std::cout << std::endl;
}

void InitializeArray(int (&ia)[N], int n) {
  for (int i = 0; i < n; ++i)
    ia[i] = 0;
}

int Deduplicate(int (&ia)[N], int(&res_ia)[N], int n) {
  // ia: sorted array
  int cnt = 0;
  InitializeArray(res_ia, n);
  for (int i = 0, j = 0; i < n; ++i) {
    if (i > 0 && ia[i] == ia[i - 1])
    //if (ia[i] == ia[i - 1])
      continue;
    res_ia[j++] = ia[i];
    ++cnt;
  }
  return cnt;
}

void DeduplicateCount(int (&ia)[N], int n){
  // count recurrence and print
  // ia: sorted array
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    while (i < n - 1 && ia[i] == ia[i + 1]) {
      ++cnt;
      ++i;
    }
    std::cout << ia[i] << " " << cnt << std::endl;
    cnt = 1;
  }
}


//void AssignIntArray(int (&ia)[N], int &n) {
void AssignIntArray(int (&ia)[N], int &n) {
  //scanf("%d", n);
  std::cin >> n;
  // int input;
  for (int i = 0; i < n; ++i) {
    //scanf("%d", &ia[i]);
    std::cin >> ia[i];
    //cin >> input;
    //ia.push_back(input);
  }
}

int main() {
  int n = 0;
  int ia[N] = {0};
  //std::vector<int> ia;
  int res_ia[N] = {0};
  AssignIntArray(ia, n);

  //PrintIntArray(ia, N);
  CountSort(ia, res_ia, n);
  PrintIntArray(ia, n);
  
  // remove deduplicated and print
  /*
  int deduplicated_ia[N];
  int len = Deduplicate(res_ia, deduplicated_ia, n);
  std::cout << len << std::endl;
  PrintIntArray(deduplicated_ia, len);
  */

  //  remove deduplicated elements and print recurrence
  //PrintIntArray(res_ia, n);
  //DeduplicateCount(res_ia, n);
}

// tumor native