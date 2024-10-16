
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    vector<char> buf;
    constexpr size_t buf_size = 1e4;
    buf.resize(buf_size);
    out.rdbuf()->pubsetbuf(buf.data(), buf_size);
    vector<int> result;
    result.reserve(1e4);
    string in;
    while (getline(cin, in))
    {
        result.clear();
        for (size_t i = 0, s = size(in); i < s; ++i)
        {
            const char c = in[i];
            const bool is_num = (c >= '0') && (c <= '9') || (c == '-');
            if (!is_num)
            {
                continue;
            }
            else
            {
                char* off;
                result.push_back(strtol(&in[i], &off, 10));
                i += (off - &in[i]);
            }
        }
        sort(begin(result), end(result));
        out << '[';
        for (size_t i = 0, s = size(result); i < s; ++i)
        {
            if (0 != i)
                out << ',';
            out << result[i];
        }
        out << "]\n";
    }
}
#define main _
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode dummy;
        ListNode* tail = &dummy;
        dummy.next = nullptr;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            ListNode* list1 = lists[0];
            ListNode* list2 = lists[1];
            ListNode* merged = mergeTwoLists(list1, list2);
            lists.push_back(merged);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }

        return lists[0];
    }
};