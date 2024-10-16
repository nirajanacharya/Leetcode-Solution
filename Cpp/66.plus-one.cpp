class Solution {
public:

    void check(vector<int>& digits, int i){
        if(digits[i]==10 && i>0){
            digits[i--]=0;
            digits[i]++;
            check(digits, i);
        }
        else if(digits[i]==10 && i == 0){
            digits.insert(digits.begin()+1,0);
            digits[0]=1;
        }
        return;
    }
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        digits[i]++;
        check(digits, i);
        return digits;
    }
};