//usr/bin/env g++ --std=c++14 algorithms-5.cpp -o alg5; ./alg5; exit

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
      return right-left;
    }

    string longestPalindrome(string s) {
      int substr_start=0;
      size_t substr_length = 0;
      for (int i=0; i<s.size(); ++i) {
        auto len1 = expandCandidate(s,i,i);
        auto len2 = expandCandidate(s,i,i+1);
        auto len = std::max(len1, len2);
        if (len > substr_length) {
          substr_length = len;
          substr_start = i - (substr_length-1)/2;
        }
      }
      return s.substr(substr_start,substr_length-1);
    }
};

int main(int argc, char** argv) {

  Solution s;

  string test = "babacabbabababcb";
  auto result = s.longestPalindrome(test);
  cout << "test: " << test << endl << "result: " << result << endl << endl;

}


