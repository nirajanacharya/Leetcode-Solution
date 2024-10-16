class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        int l1=num1.length();
        int l2=num2.length();
        vector<int>res(l1+l2,0);
        int i=l2-1;
        int pf=0;
        while(i>=0){
            int ival=num2[i]-'0';
            
            int j=l1-1;
            int k=res.size()-1-pf;
            int carry=0;
            while(j>=0||carry!=0){
                int jval=j>=0?num1[j]-'0':0;
                j--;
                int prod=ival*jval+carry+res[k];
                res[k]=prod%10;
                carry=prod/10;
                k--;

            }
            pf++;
            i--;

        }
        //managment of leading zero using general methord
        string str="";
        bool flag=false;
        for(int val:res){
            if(val==0 && flag == false){
                //leading zero
                continue;

            }
            else{
                flag =true;
                str+=val+'0';
            }
        }
        return str;
    }
};
