//usr/bin/env g++ --std=c++14 add_two_numbers.cpp -o add_two_numbers; ./add_two_numbers; rm add_two_numbers; exit
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      std::string substr = "";
      size_t longest = s.empty() ? 0 : 1;
      for (auto& chr : s) {
        //cout << "\tchr: " << chr << endl;
        //cout << "\t\tsubstr: " << substr << endl;
        auto loc = substr.find(chr);
        if (loc == string::npos) {
          substr += chr;
          cout << "\t\tnew substr: " << substr << endl;
        } else {
          if (substr.size() > longest) {
            longest = substr.size();
            //cout << "\t\tnew longest: " << substr << ", " << longest << endl;
          }
          substr.erase(0,loc+1);
          substr += chr;
        }
      }
      return std::max(longest, substr.size());
    }
};

int main (int argc, char** argv) {

  vector<string> tests {
    "",
    "a",
    "aa",
    "aba",
    "abacaba",
    "abc"
  };
  Solution s;

  for (auto& test : tests) {
    cout << "test: \"" << test << "\""<< endl;
    auto len = s.lengthOfLongestSubstring(test);
    cout << "result: " << len << endl;
  }
  return 0;
}
