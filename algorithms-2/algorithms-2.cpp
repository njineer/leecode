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

class Solution {
  public:
    ListNode* copyList(ListNode* l1) {
      ListNode* fromList = l1;
      ListNode* toList = new ListNode(fromList->val);
      ListNode* result = toList;
      fromList = fromList->next;
      while(fromList) {
        toList->next = new ListNode(fromList->val);
        toList = toList->next;
        fromList = fromList->next;
      }
      return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // create result linked list
      ListNode* result;

      // check for x+0
      if (l1->val == 0 && !l1->next)
        result = copyList(l2);
      else if (l2->val == 0 && !l2->next)
        result = copyList(l1);
      else {
        result = new ListNode(0);

        // tmp variables
        ListNode *cur = result, *inl1 = l1, *inl2 = l2;
        int carry = 0;

        // for each digit/node
        while (inl1 && inl2) {
          cout << "result: ";printList(result);
          // find sum
          int tmp = inl1->val + inl2->val + carry;
          cout << "tmp: " << tmp << endl;
          // carry if necessary
          if (tmp < 10) {
            cur->val = tmp;
            carry = 0;
          } else {
            cur->val = tmp % 10;
            carry = tmp / 10;
          }
          // next digit
          inl1 = inl1->next;
          inl2 = inl2->next;
          if (inl1 || inl2) {
            cur->next = new ListNode(0);
            cur = cur->next;
          }
        }
        auto rem = inl1 ? inl1 : inl2;
        // final carry
        if (rem) {
          cur->val = carry + rem->val;
          rem = rem->next;
          while(rem) {
            cur->next = new ListNode(rem->val);
            cur = cur->next;
            rem = rem->next;
          }
        }
        else if (carry) {
          cur->next = new ListNode(carry);
        }
      }
      return result;
    }
};

int main(int argc, char** argv) {

  Solution s;

  std::vector<int> l1 {0}, l2 {5,6,4};

  auto ln1 = make_list(l1);
  auto ln2 = make_list(l2);

  cout << "in1: ";printList(ln1);
  cout << "in2: ";printList(ln2);

  auto lnr = s.addTwoNumbers(ln1, ln2);
  cout << "result list: ";printList(lnr);
}


