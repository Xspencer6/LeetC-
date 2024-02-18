#include <unordered_map>
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr){
            if (temp->val == temp->next->val){
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;
    }
};

void printLink(ListNode* l){
    while (l != nullptr){
        if (l->next != nullptr) std::cout << l->val << "->";
        else std::cout << l->val;
        l = l->next;
    }
}

int main(){
    Solution s;
    // singly linked list
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(3);

    printLink(s.deleteDuplicates(l1));

    return 0;
}