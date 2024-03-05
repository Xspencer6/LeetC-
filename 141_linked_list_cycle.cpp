#include "LinkedList.h"
#include <unordered_map>

bool hasCycle(ListNode* head){
    ListNode* tortoise = head;  // slow 
    ListNode* hare = head->next;    // fast
    while (hare != nullptr && hare->next != nullptr){
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            return true;
        }  // if they meet, theres a cycle
    }
    return false;
}
