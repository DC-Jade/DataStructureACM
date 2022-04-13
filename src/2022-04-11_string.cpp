#include <iostream>
using namespace std;

// char array
void ReversePrintCharArray() {
  char word1[100], word2[100], word3[100];
  cin >> word1 >> word2 >> word3;
  cout << word3 << " "
       << word2 << " "
       << word1 << endl;
}

// string
void ReversePrintString() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout << s3 << " "
       << s2 << " "
       << s1 << endl;
}

int main() {
  ReversePrintCharArray();
  ReversePrintString();
}
