class Solution {
public:
    int length(ListNode* head){
        ListNode* temp = head;
        if(!temp) return 0;
        int ans = 0;
        while(temp){
            ans++;
            temp = temp->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        n = len - n;
        if(len == 1 and n == 0) return nullptr;
        if(n == 0) return head->next; 
        ListNode* curr = head;
        while(n > 1 and curr){
            curr = curr->next;
            n--;
        }
        if(curr->next == nullptr){
            curr = nullptr;
        }
        else{
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        return head;
    }
};
