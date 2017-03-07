//usr/bin/env g++ --std=c++14 reverse_int.cpp -o reverse_int; ./reverse_int; exit

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <iomanip>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
      int rev_x = 0;
      bool prev_msb=false, msb=false;
      bool overflow = false;
      while(x) {
        // overflow check
        if (rev_x > INT32_MAX/10 || rev_x < INT32_MIN/10) {
          overflow = true;
          break;
        }

        // next digit
        rev_x = (rev_x*10) + (x % 10);
        x /= 10;
      }
      if (overflow)
        return 0;
      else 
        return rev_x;
    }
};

int main(int argc, char** argv) {

  Solution s;
  vector<int> tests {
    0,
    10,
    101,
    123321,
    1234567,
    -1234567,
    1000000003
  };

  for (auto& test : tests) {
    int result = s.reverse(test);
    cout << "test: " << test << endl << "result: " << result << endl << endl;
  }
  cout << std::hex << "INT_MAX: "<< INT32_MAX << endl << "INT_MIN: " << INT32_MIN << endl;
}


