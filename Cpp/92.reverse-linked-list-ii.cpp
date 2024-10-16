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
    ListNode* reverseLeftRight(ListNode* head, int left, int right) {
        if (head == NULL || left > right)
            return head;
        int index = 0;
        ListNode* left_pre = NULL;
        ListNode* right_pre = NULL;
        ListNode* left_ptr = NULL;
        ListNode* right_ptr = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL) {
            ++index;
            if (index == left) {
                left_pre = slow;
                left_ptr = fast;
            }
            if (index == right) {
                right_pre = slow;
                right_ptr = fast;
            }
            slow = fast;
            fast = fast->next;
        }
        if (left_ptr == NULL || right_ptr == NULL)
            return head;

        ListNode* left_next = left_ptr->next;
        ListNode* right_next = right_ptr->next;
        if (left == 1 && right-left==1) { // left==head,left==right_pre
            head = right_ptr;
            right_ptr->next = left_ptr;
            left_ptr->next = right_next;
        } else if (left == 1 && left_next == right_pre) {//left==head,left_next==right_pre
            head = right_ptr;
            right_ptr->next = left_next;
            right_pre->next = left_ptr;
            left_ptr->next = right_next;
        } else if (left == 1) {//left==head
            cout<<"left 1"<<endl;
            head = right_ptr;        
            //left_pre->next = right_ptr;
            right_ptr->next = left_next;
            right_pre->next = left_ptr;
            left_ptr->next = right_next;

        } else if (right - left == 1) { // left==right_pre
            left_pre->next = right_ptr;
            right_ptr->next = left_ptr;
            left_ptr->next = right_next;
        } else {
            left_pre->next = right_ptr;
            right_ptr->next = left_next;
            right_pre->next = left_ptr;
            left_ptr->next = right_next;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        while (left < right) {
            head=reverseLeftRight(head, left, right);
            ++left;
            --right;
        }

        return head;
    }
};