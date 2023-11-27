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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry){
            int sum = 0;

            if (l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10; // store if there's carry for next iter
            ListNode* newNode = new ListNode(sum%10);   // store the sum of l1 and l2 to new node
            temp->next = newNode;   // add a new node to end of temp
            temp = temp->next; // move forward to newly assigned node.
        }

        return dummy->next; // dummy points to first item of temp
    }
};
