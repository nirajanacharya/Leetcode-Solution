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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        for(ListNode* p = head; p != nullptr; p = p -> next)
            ++count;
        
        if(count == 1){
            head = nullptr;
            return head;
        }

        int i = 1;
        for(ListNode* p = head; p != nullptr; p = p -> next){
            if(count-n == i){
                ListNode* temp = p -> next;
                p -> next = temp -> next;
                return head;
            }
            else if(count == n){
                ListNode* temp = p ->next;
                p -> val = temp -> val;
                p -> next = temp -> next;
                return head;
            }
            ++i;
        }
        return nullptr;
    }
};