
 // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move second pointer n+1 steps ahead
        // This ensure a gap of n nodes between first and second 
        for (int i = 0; i <= n; ++i) {
            second = second->next;
        }

        // Move both pointers until second reaches the end
        // At the end of the while first will be place at the node before the one to be removed
        while (second) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node
        ListNode* temp = first->next;
        first->next = temp->next; // the next pointer of first is adjusted to skip the node to be removed
        delete temp; // The memory allocated for the node to be removed (temp) is freed using deleted 

        return dummy->next; 
    }
};
