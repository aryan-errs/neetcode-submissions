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
    // int len(ListNode* list){
    //     int n = 0;
    //     while(list != nullptr){
    //         n++; list = list->next;
    //     }
    //     return n;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int n1 = len(list1), n2 = len(list2);
        ListNode* Dummy = new ListNode(0);
        ListNode* temp = Dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int v1 = l1 != nullptr? l1->val : 0;
            int v2 = l2 != nullptr? l2->val : 0;
            int sum = v1 + v2 + carry;
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = newNode;
            carry = sum / 10;
            l1 = l1 != nullptr? l1->next: nullptr;
            l2 = l2 != nullptr? l2->next : nullptr;
        }
        return Dummy->next;
    }
};
