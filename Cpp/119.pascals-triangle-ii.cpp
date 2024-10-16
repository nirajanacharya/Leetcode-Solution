class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v1(1, 1);
        vector<int> v2;
        vector<int>* prev = &v2;
        vector<int>* curr = &v1;
        
        for (int row = 1; row <= rowIndex; ++row) {
            swap(curr, prev);
            curr->clear();
            curr->push_back(1);
            for (int col = 1; col < row; ++col) {
                curr->push_back((*prev)[col-1] + (*prev)[col]);
            }
            curr->push_back(1);
        }
        return *curr;
    }
};