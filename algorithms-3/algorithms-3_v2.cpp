//usr/bin/env g++ --std=c++14 algorithms-3.cpp -o alg3; ./alg3; rm alg3; exit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      std::map<char, int> substr {};
      size_t longest = s.empty() ? 0 : 1;
      int dup=0;
      for (int i=0; i<s.size(); ++i) {
        auto chr = s[i];
        auto loc = substr.find(chr);
        if (loc != substr.end()) {
          dup =  substr[chr];
        } 
        substr[chr] = i;
        longest = std::max(longest, dup);
      }
      return longest;
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
