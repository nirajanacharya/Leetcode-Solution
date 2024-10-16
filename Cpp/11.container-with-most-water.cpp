#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool Booster = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return true;}();inline bool is_digit(char c) { return c >= '0' && c <= '9';}std::array<int, 100000> nums;void parse_input_and_solve(std::ofstream& out, const std::string& s) { const int N = s.size(); int left = 0; int idx = 0; while (left < N) { if (!is_digit(s[left])) { ++left; continue; } int right = left; int value = 0; while (right < N && is_digit(s[right])) { value = value * 10 + (s[right] - '0'); ++right; } left = right; nums[idx] = value; ++idx; }  int area = 0, i = 0, j = idx-1; label:  area = max(area, (j-i)*min(nums[i], nums[j])); if(nums[i] < nums[j]) i++; else j--; if(i < j) goto label; out<<area<<"\n";}bool Solve = [](){ std::ofstream out("user.out"); for (std::string s; std::getline(std::cin, s);) { parse_input_and_solve(out, s); } out.flush(); exit(0); return true;}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int maxi=0;
        while(s<e){
            int cur=min(height[s],height[e])*(e-s);
            maxi=max(maxi,cur);
            if(height[s]<height[e]){
                s++;
            } else{
                e--;
            }
        }
        return maxi;
    }
};