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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode    head;   // head is a new ListNode Object. It will be used as head of the returned list
        ListNode*   tail;   // tail is a pointer to a ListNode Object.
        tail = &head;       // We point the pointer tail to the head List

        while(l1!=NULL || l2!=NULL) 
        {
            if(!l2) { tail->next = l1; break; }
            if(!l1) { tail->next = l2; break; }

            else if(l1->val < l2->val) 
            {
                tail->next = l1; // tail will point to l1 list.
                l1 = l1->next;   // l1 became the tail of l1 list.
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        return head.next;

};
};
