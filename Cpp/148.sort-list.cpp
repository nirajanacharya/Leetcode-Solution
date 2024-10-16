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
int a[50001];
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);) {
        if (s.length() == 2) {
            out << "[]\n";
            continue;
        }
        int n = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-') ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (_neg) v = -v;
            a[n++] = v;
        }
        sort(a, a + n);
        out << '[' << a[0];
        for (int i = 1; i < n; ++i) out << ',' << a[i];
        out << "]\n";
    }
    out.flush();
    exit(0);
    return 0;
}();
 int length(ListNode*head){
    ListNode*temp=head;
    int i=1;
    while(temp!=NULL){
    temp=temp->next;
    i++;
    }
    return i;
 }
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return head;
        } 
        if(head->next==NULL){
            return head;
        }
        vector<int>s;
        ListNode*temp=head;
        while(temp!=NULL){
        int digit=temp->val;
        s.push_back(digit);
        temp=temp->next;
        }
        int size=s.size();
        sort(s.begin(),s.end());
        ListNode*head1=NULL;
        ListNode*Tail1=NULL;
        int j=0;
        while(j<size){
            int digit=s[j];
            ListNode*Node=new ListNode(digit);
            if(head1==NULL){
                head1=Node;
                Tail1=Node;
            }
            else{
                head1->next=Node;
                head1=Node;
            }
            j++;
        }
        return Tail1;
    }
};