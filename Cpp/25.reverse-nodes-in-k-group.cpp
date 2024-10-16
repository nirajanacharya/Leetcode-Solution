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
    void reverse(ListNode* first, ListNode* last,ListNode* pre,ListNode* &head){
        if(pre){
            pre->next=last;
        }
        else{
            head=last;
        }
        ListNode* nu=last->next;
        ListNode* prev=nullptr,*curr=first,*next=nullptr;
        while(curr!=nu){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        first->next=nu;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1){
            return head;
        }
        
        ListNode *temp=head,*first=nullptr,*prev=nullptr,*pre=nullptr;
        int count=1;
        for(temp=head;temp!=nullptr;temp=temp->next){
            if(count%k==1){
                first=temp;
                pre=prev;
            }
            if(count%k==0){
                reverse(first,temp,pre,head);
                temp=first;
            }
            prev=temp;
            count++;
        }
        return head;
    }
};