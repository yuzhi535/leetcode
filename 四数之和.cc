class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        // vector<vector<int> > ans;
        if (nums.size() < 4)     //判处特殊情况
            return vector<vector<int> > {};

        sort(nums.begin(), nums.end());
        
        
        vector<vector<int>> ans;
        int index, i, j, k;
        for (index = 0; index < nums.size() - 3; ++index)
        {
            if (index != 0 && nums[index] == nums[index - 1])
                continue;
            if ( 4 * nums[index] > target)
                return ans;
            if (nums[index] + 3 * nums[nums.size() - 1] < target)
                continue;
            for (i = index + 1; i < nums.size() - 2; ++i)
            {
                if (i != index + 1 && nums[i] == nums[i - 1])
                    continue;
                if (nums[index] + 3 * nums[i] > target)
                    break;
                if (nums[index] + nums[i] + 2 * nums[nums.size() - 1] < target)
                    continue;
                j = 1 + i; k = nums.size() - 1;
                while (j < k)
                {
                    if (nums[index] + nums[i] + 2 * nums[j] > target)
                        break;
                    int temp = nums[i] + nums[j] + nums[k] + nums[index];
                    if (temp == target)
                    {
                        if ( (j == i + 1 ? 1 : (nums[j] != nums[j - 1]) && (k == nums.size() - 1 ? 1 : (nums[k] != nums[k + 1]))))  
                        {
                            ans.push_back({ nums[index], nums[i], nums[j], nums[k] });
                        }
                        ++j;
                        --k;
                    }
                    else if (temp < target)
                        ++j;
                    else if (temp > target)
                        --k;
                }
            }
        }

        return ans;
    }
};
