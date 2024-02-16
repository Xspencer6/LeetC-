#include <iostream>
#include <vector>
using namespace std;

struct ListNode{    // singly linked list
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}  // default constructor
    ListNode(int x): val(x), next(nullptr) {} // constructor with x val 
    ListNode(int x, ListNode* next): val(x), next(next) {} // constructor with both x and next ptr
};
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry){     // this loop will continue as long as both linked list is not exhausted or there is value in carry
            int sum = 0;
            if (l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;   // add current carry to sum
            carry = sum / 10; // stores the carry if there's any
            // store value of sum / 10
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
            // check for possible carry
        }
        return dummy->next;
    }

};

void print_list(ListNode* l){
    ListNode* head = l;
    while (head != nullptr){
        if (head->next == nullptr) {
            cout << head->val; 
            return;
        } 
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    print_list(s.addTwoNumbers(l1, l2));
    return 0;
}