#include "LinkedList.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = new ListNode(0);
        // uses to pointer slow and fast to monitor the node before the n remove
        ListNode* slow = curr, *fast = curr;

        for (int i = 0; i < n; i++){
            fast = fast->next;
        }

        // move slow and fast while keeping the n distance from slow and fast
        while (fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        // now we know that the next node is the one we need to remove, move slow pointer->next
        slow->next = slow->next->next;
        return curr->next;
    }