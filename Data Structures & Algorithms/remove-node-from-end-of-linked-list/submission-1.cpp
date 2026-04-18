/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int k = 0;
    ListNode* r = head;

    while (r) {
      r = r->next;
      k++;
    }

    if (n == k) {
      ListNode* t = head->next;
      head->next = nullptr;
      return t;
    }

    int i = k - n - 1;
    r = head;

    while (i > 0) {
      r = r->next;
      i--;
    }

    ListNode* t = r->next;
    r->next = r->next->next;
    t->next = nullptr;

    return head;
  }
};
