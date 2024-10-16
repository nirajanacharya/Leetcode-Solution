class Solution {
public:
    int romanToInt(string s) {
        int length = s.length(), tot = 0, pre = 0;
        for (int i = length - 1; i >= 0; i--) {
            int value = toInt(s[i]);
            if (value < pre)
                tot -= value;
            else
                tot += value;
            pre = value;
        }
        return tot;
    }
    int toInt(char c) {
        switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
        }
    }
};