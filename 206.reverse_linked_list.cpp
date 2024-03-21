#include "LinkedList.h"

ListNode* reverseList(ListNode* head){
    ListNode* curr = head;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;

    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}