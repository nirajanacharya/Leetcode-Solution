/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        int ans = stoi(str);
        for (int i = 0; i < 4; ++i) cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (ans) cout << "Intersected at \'" << ans << '\'';
        else cout << "No intersection";
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 return nullptr;
    }
};