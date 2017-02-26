//usr/bin/env g++ --std=c++14 algorithms-3.cpp -o alg3; ./alg3; rm alg3; exit
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      std::string substr = "";
      size_t longest = 1;
      for (auto& chr : s) {
        auto loc = substr.find(chr);
        if (loc == string::npos) {
          substr += chr;
        } else {
          if (substr.size() > longest) {
            longest = substr.size();
          }
          substr.clear();
          substr += chr;
        }
      }
      return longest;
    }
};

int main (int argc, char** argv) {

  string str = "aaaaaaaa";
  Solution s;

  cout << "str: " << str << endl;
  auto len = s.lengthOfLongestSubstring(str);
  cout << "len: " << len << endl;
  return 0;
}
