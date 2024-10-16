class Solution {
public:
    string addBinary(string a, string b) {
        auto ita = a.rbegin(), itb = b.rbegin();
        int carry = 0;
        string result = "";
        while (ita != a.rend() && itb != b.rend()) {
            int A = *ita - '0', B = *itb - '0';
            result += ((carry + A + B) & 1) + '0';
            carry = ((carry + A + B) & 2) == 2;
            ita++;
            itb++;
        }
        while (ita != a.rend()) {
            int A = *ita - '0';
            result += ((carry + A) & 1) + '0';
            carry = ((carry + A) & 2) == 2;
            ita++;
        }
        while (itb != b.rend()) {
            int B = *itb - '0';
            result += ((carry + B) & 1) + '0';
            carry = ((carry + B) & 2) == 2;
            itb++;
        }
        if (carry) result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};