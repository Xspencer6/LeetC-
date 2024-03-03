#include "LinkedList.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* left = head, *right = head;

    for (int i = 0; i < n; i++) right = right->next;// move right so that there will be n distance between left and right

    if (!right) return head->next;

    while(right->next != nullptr){
        left = left->next;
        right = right->next;
    }
    // now we know that the next node of left is the N node that we want to remove
    // skip it
    left->next = left->next->next;
    return head;
    }   