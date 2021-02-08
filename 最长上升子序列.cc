class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 2)                 //排除特殊情况
            return nums.size();
        vector<int> ans(1, 0);
        ans[0] = nums[0];
        int len = 1;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (ans[len - 1] < nums[i])      //若新处理的值大，则加入
            {
                ans.push_back(nums[i]);
                ++len;
            }
            else                             //否则，与在vevtor中的最接近的小于它的值进行替换          
            {
                int left = 0, right = ans.size() - 1;
                while (left < right)              //通过二分法找到最接近目前所处理的值的位置，进行替换
                {   
                    int middle = (left + right) / 2;
                    if (ans[middle] == nums[i])
                    {
                        left = middle;
                        break;
                    }
                    else if (ans[middle] < nums[i])
                        left = middle + 1;
                    else
                        right = middle;
                }
                ans[left] = nums[i];
            }
        }
        return len;
    }
};
