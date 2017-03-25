//usr/bin/env g++ --std=c++14 palindrome_number.cpp -o palindrome_number; ./palindrome_number; exit

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {

  private:
    static const std::array<int,9> powers_of_10;

  public:
    int find_highest_digit (int n) {
      if (n <= 0) return 0;
      if (n > powers_of_10.back()) return powers_of_10.back();
      int upper=powers_of_10.size() - 1, lower=0;
      int mid = (upper-lower)/2;
      while (lower <= upper) {
        if (n >= powers_of_10[mid]) { 
          if (n <= powers_of_10[mid+1]) {
            return powers_of_10[mid];
          } else {
           lower = mid+1;
          }
        } else {
          upper = mid-1;
        }
        mid = lower + (upper-lower)/2;
      }
      return 0;
    }

    // going for an iterator-ish approach
    //  compare digits, increment/decrement
    // but... didn't think using modulo and division for digit comparison all the way through 
    // maybe still potential here though
    bool isPalindrome(int x) {
      if (x < 0) return false;
      bool result = true;
      int high = find_highest_digit(x), low = 10;
      cout << "highest digit: " << high << endl;
      while (high > low) {
        cout << "x: " << x << "\thigh: " << high << endl;
        result &= (x/high == x%low);
        high /= 100;
        x /= 10;
      }
      return result;
    }
};

const std::array<int,9> Solution::powers_of_10 = {
      10,
      100,
      1000,
      10000,
      100000,
      1000000,
      10000000,
      100000000,
      1000000000
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
    int result = s.isPalindrome(test);
    cout << "test: " << test << endl << "result: " << result << endl << endl;
  }
}


