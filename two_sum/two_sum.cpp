//usr/bin/env g++ --std=c++14 two_sum.cpp -o two_sum; ./two_sum; exit

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

void printList(ListNode* ln) {
  ListNode* tmp = ln;
  while (tmp != nullptr) {
    cout << tmp->val << ", ";
    tmp = tmp->next;
  }
  cout << endl;
}

ListNode* make_list(std::vector<int>& init) {
  ListNode* ln = new ListNode(init[0]); 
  ListNode* cur = ln;
  for (int i=0; i<init.size()-1; ++i) {
    cur->val = init[i];
    cur->next = new ListNode(init[i+1]);
    cur = cur->next;
  }
  return ln;
}

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // create result linked list
      ListNode* head = new ListNode(0);

      // tmp variables
      ListNode *cur = head, *inl1 = l1, *inl2 = l2;
      int carry = 0;

      // for each digit/node
      while (inl1 || inl2) {
        // find sum
        int tmp = (inl1 ? inl1->val : 0) + (inl2 ? inl2->val : 0) + carry;
        cur->next = new ListNode(tmp % 10);
        carry = tmp / 10;
        // next digit
        if (inl1) inl1 = inl1->next;
        if (inl2) inl2 = inl2->next;
        cur = cur->next;
      }
      if (carry) {
        cur->next = new ListNode(carry);
      }
      auto result = head->next;
      delete head;
      return result;
    }
};

int main(int argc, char** argv) {

  Solution s;

  std::vector<int> l1 {1}, l2 {9, 9};

  auto ln1 = make_list(l1);
  auto ln2 = make_list(l2);

  cout << "in1: ";printList(ln1);
  cout << "in2: ";printList(ln2);

  auto lnr = s.addTwoNumbers(ln1, ln2);
  cout << "result list: ";printList(lnr);
}


