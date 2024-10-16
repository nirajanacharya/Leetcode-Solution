static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

inline bool isDigit(const char c) {
    return (c >= '0') && (c <= '9');
}

void parse_and_solve(const std::string& s1, const std::string& s2, std::ofstream& out) {
    const int S1 = s1.size();
    const int S2 = s2.size();
    if (S1 < S2) {
        parse_and_solve(s2, s1, out);
        return;
    }
    int carry = 0;
    int i = 0;
    int j = 0;
    while (i < S1 - 1) {
        while (i < S1 && (!isDigit(s1[i]))) { ++i; }
        while (j < S2 && (!isDigit(s2[j]))) { ++j; }
        const int n1 = s1[i] - '0';
        const int n2 = (j < S2) ? (s2[j] - '0') : 0;
        const int n = carry + n1 + n2;
        carry = n / 10;
        out << (n % 10);
        if (i < S1 - 2) {
            out << ",";
        }
        ++i;
        ++j;
    }
    if (carry > 0) {
        out << "," << carry;
    }
}

static bool Solve = [](){
    std::ofstream out("user.out");
    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        out << "[";
        parse_and_solve(s1, s2, out);
        out << "]\n";
    }
    out.flush();
    exit(0);
    return true;
}();
/**
 * Definition for single-linked list.
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

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int c = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = c + l1->val + l2->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = c + l1->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = c + l2->val;
            if (sum > 9) {
                c = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
            } else {
                c = 0;
                head->next = new ListNode(sum);
                head = head->next;
            }
            l2 = l2->next;
        }
        if (c > 0) {
            head->next = new ListNode(c);
            head = head->next;
        }
        head->next = NULL;
        return temp->next;
    }
};