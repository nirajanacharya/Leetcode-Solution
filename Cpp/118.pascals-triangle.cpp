class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> v1;
        v1.push_back(1);
        v.push_back(v1);
        for(int i=1;i<numRows;i++)
        {
            vector<int> v2;
            v2.push_back(1);
            for(int j=1;j<v[i-1].size();j++)
            {
                v2.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v2.push_back(1);
            v.push_back(v2);
        }
        return v;
    }
};