//usr/bin/env g++ --std=c++14 atoi.cpp -o atoi; ./atoi; rm atoi; exit

#include <iostream>
#include <vector>
#include <regex>
#include <cstdint>
#include <string>

using namespace std;

class Solution {

private:
  private:
    static const regex re_base10;
    static const regex re_base2;
    static const regex re_base16;
    static const map<char, int> char_to_int;

  public:
    int myAtoi(string str) {
      int64_t result = 0;
      int sign = 1;
      smatch re_match;
      auto match = regex_search(str, re_match, re_base10); 
      if (!re_match.empty()) {
        sign = re_match.str(1) == "-" ? -1 : 1;
        for (auto& chr : re_match.str(2)) {
          result = result*10 + char_to_int.at(chr);  
          if (sign * result > INT32_MAX) {
            result = INT32_MAX;
            break;
          } else if (sign * result < INT32_MIN) {
            result = INT32_MIN;
            break;
          }
        }
      } 
      return sign*result;
    }
};

const regex Solution::re_base10("^\\s*([+-])?([0-9]+).*$");
const regex Solution::re_base2("^\\s*([+-])?([01]+).*$");
const regex Solution::re_base16("^\\s*([+-])?([0-9A-Za-z]+).*$");
const map<char, int> Solution::char_to_int {
  {'0', 0},  {'1', 1},  {'2', 2},  {'3', 3},  {'4', 4},
  {'5', 5},  {'6', 6},  {'7', 7},  {'8', 8},  {'9', 9},
  {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15},
  {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
};


int main(int argc, char** argv) {

  Solution s;
  vector<string> tests {
    "0",
    "1",
    "+2",
    "10",
    "-101",
    "123321",
    "1234567",
    "-1234567",
    "1000000003",
    "3000000001",
    "              0",
    "1             ",
    "-2147483648",
    "-2147483649",
    "9999999999999999999999999999",
    "9223372036854775809",
  };

  for (auto& test : tests) {
    cout << "test: " << test << endl;
    int result = s.myAtoi(test);
    cout << "\tresult: " << result << endl << endl;
  }
  return 0;
}

