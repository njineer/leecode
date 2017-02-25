//usr/bin/env g++ --std=c++14 algorithms-2.cpp -o alg2; ./alg2; exit

#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* result = new ListNode(0);
      ListNode* cur = result, *inl1 = l1, *inl2 = l2;
      int carry = 0;
      while (inl1 && inl2) {
        int tmp = inl1->val + inl2->val + carry;
        if (tmp < 10) {
          cur->val = tmp;
          carry = 0;
        } else {
          cur->val = tmp % 10;
          carry = tmp / 10;
        }
        if (inl1->next && inl2->next) {
          cur->next = new ListNode(0);
          cur = cur->next;
        }
        inl1 = inl1->next;
        inl2 = inl2->next;
      }
      if (carry) {
        cur->next = new ListNode(carry);
      }
      return result;
    }
};

void printList(ListNode* ln) {
  ListNode* tmp = ln;
  while (tmp != nullptr) {
    cout << tmp->val << ", ";
    tmp = tmp->next;
  }
  cout << endl;
}

ListNode* make_list(std::vector<int>& init) {
  ListNode* ln = new ListNode(0); 
  ListNode* cur = ln;
  for (int i=0; i<init.size()-1; ++i) {
    cur->val = init[i];
    cur->next = new ListNode(init[i+1]);
    cur = cur->next;
  }
  return ln;
}

int main(int argc, char** argv) {

  Solution s;

  std::vector<int> l1 {2,4,3}, l2 {5,6,4};

  auto ln1 = make_list(l1);
  auto ln2 = make_list(l2);

  printList(ln1);
  printList(ln2);

  auto lnr = s.addTwoNumbers(ln1, ln2);
  printList(lnr);
}


