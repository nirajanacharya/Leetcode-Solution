class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z' )
            {
                s1.push_back(s[i]+32);  
            }
            else if(s[i]>='a' && s[i]<='z')
            s1.push_back(s[i]);
            else if(s[i]>='0' && s[i]<='9')
            s1.push_back(s[i]);
        }
        string s2=s1;
        reverse(s2.begin(),s2.end());
        if(s2==s1)
        {
            return 1;
        } 
        return 0;  
          
    }
};