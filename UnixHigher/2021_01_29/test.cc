#include <iostream>
using namespace std;

#define MAX_INTEGER 999999999

int main() {
  double a = 1.0, b = 1.0, c = 1.0;
  double result = 4.0;
  for (double i = 1.0; i < MAX_INTEGER; ++i) {
    for (double j = 1.0; j < MAX_INTEGER; ++j) {
      for (double k = 1.0; k < MAX_INTEGER; ++k) {
        a = i;
        b = j;
        c = k;
        cout << "result" << a / (b + c) + b / (a + c) + c / (a + b) << endl;
        if ((a / (b + c) + b / (a + c) + (c / (a + b)) == result) {
          cout << "a:" << a << "b:" << b << "c:" << c << endl;
          break;
        }
      }
    }
  }

  return 0;  
}