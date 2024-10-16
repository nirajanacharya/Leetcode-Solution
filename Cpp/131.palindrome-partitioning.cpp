class Solution {
public:
    bool check(int i,int j, string& s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void f(vector<vector<string>>& sol,vector<string>& arr, int ind,string & s){
        if(ind==s.size()){
            sol.push_back(arr);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(check(ind,i,s)){
                arr.push_back(s.substr(ind,i-ind+1));
                //cout<<ind<<s.substr(ind,i-ind+1)<<" ";
                f(sol,arr,i+1,s);
                arr.pop_back();
            }
        }
        //cout<<endl;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> sol;
        vector<string> arr;
        f(sol,arr,0,s);
        return sol;
    }
};