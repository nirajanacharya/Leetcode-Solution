class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            if(v1[0] == v2[0]) return v1[1] < v2[1];
            else return v1[0] < v2[0];
        });
        vector<vector<int>> Ans;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= end)
            {
                if(intervals[i][1] > end) end = intervals[i][1];
            }
            else
            {
                Ans.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        if(!Ans.empty() && Ans[Ans.size()-1][1] != end)
        {
            Ans.push_back(vector<int>{start, end});
        }
        if(Ans.empty()) Ans.push_back(vector<int>{start, end});
        return Ans;
    }
};