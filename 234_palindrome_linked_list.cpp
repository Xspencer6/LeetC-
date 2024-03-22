#include "LinkedList.h"

bool isPalindrome(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    // find middle
    while (fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse the list
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(slow){
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // check if palindrome
    ListNode * left = head;
    ListNode * right = prev;
    while (right){
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}