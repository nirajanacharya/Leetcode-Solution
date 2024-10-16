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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr1, *ptr2, *prePtr2, *nextPtr2;
        ptr2 = head;
        ptr1 = prePtr2 = NULL;
        while (ptr2) {
            nextPtr2 = ptr2->next;
            if (ptr2->val < x) {
                if (prePtr2 == ptr1) {
                    ptr1 = prePtr2 = ptr2;
                } else {
                    prePtr2->next = nextPtr2;
                    if (ptr1) {
                        ptr2->next = ptr1->next;
                        ptr1->next = ptr2;
                    } else {
                        ptr2->next = head;
                        head = ptr2;
                    }
                    ptr1 = ptr2;
                }
            } else {
                prePtr2 = ptr2;
            }
            
            ptr2 = nextPtr2;
        }

        return head;        
    }
};