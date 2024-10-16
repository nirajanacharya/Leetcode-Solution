class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            //opening brackets asle tr add kara
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            //closing bracket asle tr stack madhle tyachya corresponding prackect kadun taka
            else{
                    if(st.empty()){
                        return false;
                    }
                    char ch=st.top();
                    st.pop();
                    if((s[i]==')'&&ch=='(')||(s[i]=='}'&&ch=='{')||(s[i]==']'&&ch=='['))continue;
                    else{
                        return false;
                    }
            }
        }
        return st.empty();
    }
};