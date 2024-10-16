class Solution {
public:
    int largestRectangleArea(vector<int>& hs) {
    if(hs.size() == 0) return 0;
    hs.push_back(0);
    vector<int> st {-1};
    int n = hs.size();
    int result = 0;
    for(int i = 0; i < n; ++i) {
      while(st.size() > 1 && hs[st.back()] >= hs[i]) {
        int k = st.back();
        st.pop_back();
        int w = i - st.back() - 1;
        int s = hs[k] * w;
        result = max(result, s);
      }
      st.push_back(i);
    }
    return result;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();