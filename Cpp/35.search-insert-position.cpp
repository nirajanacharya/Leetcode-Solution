class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int forward_border = 0;
        int backward_border = nums.size() - 1;
        int mid_pointer = nums.size() - 1;

        if(nums[backward_border] < target) { return backward_border + 1; }

        while (forward_border < backward_border) {
            if(nums[mid_pointer] == target) { return mid_pointer; }
            if(nums[mid_pointer] < target && nums[mid_pointer + 1] > target) { return mid_pointer + 1; }
            else if (nums[mid_pointer] > target) { backward_border = mid_pointer; mid_pointer = (forward_border + backward_border) / 2; }
            else { forward_border = mid_pointer; mid_pointer = (forward_border + backward_border) / 2; }
        }

        return mid_pointer;

    }
};