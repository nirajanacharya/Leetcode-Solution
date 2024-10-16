class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string  countSay=countAndSay(n-1);

         
        string ans="";
        int m=countSay.length();
        for(int i=0;i<m;i++){
            char ch=countSay[i];
           int  cnt=1;
            while(i<m-1 and countSay[i]==countSay[i+1]){cnt++;
            i++;}
            ans+=to_string(cnt)+string(1,ch);
        }
        return ans;
    }
};