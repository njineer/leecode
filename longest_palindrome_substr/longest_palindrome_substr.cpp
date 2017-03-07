//usr/bin/env g++ --std=c++14 longest_palindrome_substr.cpp -o lps; ./lps; exit

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:

    size_t expandCandidate(const string& s, size_t left, size_t right) {
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left; 
        ++right;
      }
      return right-left-1;
    }

    string longestPalindrome(string s) {
      unsigned int substr_start=0;
      unsigned int substr_length = 0;
      for (int i=0; i<s.size(); ++i) {
        auto len1 = expandCandidate(s,i,i);
        auto len2 = expandCandidate(s,i,i+1);
        auto len = std::max(len1, len2);
        if (len > substr_length) {
          substr_start = i - (len-1)/2;
          substr_length = len;
        }
      }
      return s.substr(substr_start,substr_length);
    }
};

int main(int argc, char** argv) {

  Solution s;

  vector<string> tests {
    "b",
    "bb",
    "bbb",
    "abcba",
    "abcbad",
    "babacabbabababcb"
  };
  for (auto& test : tests) {
    auto result = s.longestPalindrome(test);
    cout << "test: " << test << endl << "result: " << result << endl << endl;
  }
}


