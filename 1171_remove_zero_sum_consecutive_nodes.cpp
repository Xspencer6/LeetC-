#include <unordered_map>
#include "LinkedList.h"

ListNode* removeZeroSumSublists(ListNode* head){
    std::unordered_map<int, ListNode*> maps;
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    dummy->next = head;
    int sum = 0;

    while(temp){
        sum += temp->val;
        if (maps.count(sum)){   // if the sum is zero
            temp = maps[sum]->next; // to prevent the hashmap value of 0
            int p = sum + temp->val;
            while (p != sum){   // remove all nodes and stop when it reaches sum which is 0
                maps.erase(p);
                temp = temp->next;
                p += temp->val;
            }
            maps[sum]->next = temp->next;   // links the dummy next to the next of deleted nodes
        }    
        else{
            maps[sum] = temp;
        }
        // move to next
        temp = temp->next;
    }
    return dummy->next;
}