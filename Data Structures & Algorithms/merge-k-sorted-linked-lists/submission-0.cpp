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
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode res(0);
        ListNode* dummy = &res;

        while(l1 && l2){
            if(l1->val <= l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }else {
                dummy->next = l2;
                l2 = l2->next;
            }

            dummy = dummy->next;
        }

        if(l1) dummy->next = l1; else dummy->next = l2;

        return res.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }

        ListNode* l1 = lists[0];

        if(!l1){
            return nullptr;
        }

        for(int i = 1; i < n; i++){
            l1 = mergeList(l1,lists[i]);
        }

        return l1;
        
    }
};
