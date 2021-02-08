//排不排除特殊情况时间差好多。。。
//用滑动窗口，用两个指针（索引）搞定


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        int left = 0, right = 1;
        while (right < nums.size())
        {
            if (nums[left] != nums[right])
            {
                nums[left + 1] = nums[right];
                ++left;
            }
            ++right;
        }
        return left + 1;
    }
};
