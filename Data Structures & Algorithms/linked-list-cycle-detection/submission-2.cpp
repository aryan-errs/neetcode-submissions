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
    bool hasCycle(ListNode* head) {
        ListNode* tort = head;
        ListNode* hare = head;
        while(hare->next and hare->next->next){
            hare = hare->next->next;
            tort = tort->next;
            if(hare == tort) break;
        }
        tort = head;
        if(hare == nullptr) return false;
        while(hare->next and hare->next->next){        
            hare = hare->next->next;
            tort = tort->next;
            if(hare == tort) return true;
        }
        return false;
    }
};
