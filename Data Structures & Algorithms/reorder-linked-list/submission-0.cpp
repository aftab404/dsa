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
  ListNode* reverseList(ListNode* head) {
    ListNode* res = nullptr;

    while (head != nullptr) {
      ListNode* int_res = new ListNode(head->val, res);
      res = int_res;
      head = head->next;
    }

    return res;
  }

  void reorderList(ListNode* head) {
    ListNode* head2 = head;

    int n = 0;

    while (head2) {
      head2 = head2->next;
      n++;
    }

    int m = n / 2;

    head2 = head;

    while (m--) {
      head2 = head2->next;
    }

    ListNode* thead2 = head2->next;

    head2->next = nullptr;

    head2 = thead2;

    head2 = reverseList(head2);

    ListNode* l1 = head;
    ListNode* l2 = head->next;

    while (head2) {
      ListNode* tl1 = l1->next;
      l1->next = head2;
      ListNode* tthead2 = head2->next;
      head2->next = l2;
      l1 = tl1;
      head2 = tthead2;
      l2 = l2->next;
    }
  }
};
