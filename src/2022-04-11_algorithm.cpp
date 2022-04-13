#include <iostream>
using namespace std;
int ChickenNum(int head, int foot){
  int rabbit, chicken;
  rabbit = (foot - 2 * head) / 2;
  chicken = head - rabbit;
  return chicken;
}

void ISBNSimulator() {
  const int len = 13;
  char ISBN[len];
  // input 
  for (int i = 0; (i < len) && cin; ++i) {
    cin >> ISBN[i];
  }

  // check format
  for (int i = 0; i < len; ++i) {
    if ((i == 1 || i == 5 || i == 11) && (ISBN[i] != '-'))
      cout << "format is worng";
  }

  // check identifier
  int identifier = 0;
  int tmp = 0;
  int j = 0;
  for (int i = 0; i < len - 2; ++i) {
    if ((i != 1) && (i != 5) && (i != 11)) {
      ++j;
      tmp = (int)ISBN[i] - '0';  // convert char to int
      identifier += tmp * j;
      // cout << i << " " << j << " " << tmp << " " << identifier << "\n";
    }
  }
  identifier = identifier % 11;
  if (identifier == (ISBN[len - 1] - '0')) {
    cout << "Right";
    return;
  } else {
    //ISBN[len - 1] = 'X';
    if (identifier == 10) {
      if (ISBN[len - 1] == 'X') {
        cout << "Right";
        return;
      }
      ISBN[len - 1] = 'X';
    } else {
      ISBN[len - 1] = identifier + '0';
    }
    for (int i = 0; i < len; ++i)
      cout << ISBN[i];
    cout << "\n";
  }
}

// TODO enum rabbit
void EnumRabbit() {
  int sum = 1;
  int type = 1;  // rabbit type 1 young 2 miidle 3 old
  for (int i = 1; i <= 12; ++i) {
    //
  }
}

int main() {
  // cout << ChickenNum(75, 216);
  ISBNSimulator();
}