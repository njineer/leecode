//usr/bin/env g++ --std=c++14 algorithms-6.cpp -o alg6; ./alg6; exit

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
  public:
    int reverse(int x) {
      int rev_x = 0;
      bool negative = x < 0;
      x = abs(x);
      while(x) {
      }

    }
};

int main(int argc, char** argv) {

  Solution s;
  vector<string> tests {
    0,
    10,
    101,
    123321,
    1000000003
  };

  for (auto& test : tests) {
    auto result = s.reverse(test);
    cout << "test: " << test << endl << "result: " << result << endl << endl;
  }
}


