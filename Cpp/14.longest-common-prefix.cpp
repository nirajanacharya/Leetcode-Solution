class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0],last=strs[strs.size()-1];
        int i=0,j=0;
        while(i<first.size() && j<last.size()){
            if(first[i]!=last[j]){
                return first.substr(0,i);
            }
            i++;
            j++;
        }
        return first.substr(0,i);
    }
};