#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;



class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {    
        vector<vector<int> > ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        int index = 0, size = nums.size();
        while (index < size - 2)
        {
            int left = index + 1, right = size - 1;
            if (index > 0 && nums[index] == nums[index - 1])
            {
                ++index;
                continue;
            }
            while (left < right)
            {
                //排除特殊情况
                if (nums[index] > 0)
                {
                    break;
                }
                if (nums[right] < 0)
                    break;
                int res = nums[index] + nums[left] + nums[right];
                if(res == 0)
                {
                    //验证是否重复
                    if (left != index + 1 && right != size - 1 && (nums[left] == nums[left - 1] || nums[right] == nums[right + 1]))
                    {
                        if (nums[left] == nums[left - 1])
                            ++left;
                        else
                            --right;
                    }
                    else
                    {
                        ans.push_back({nums[index], nums[left], nums[right]});
                        ++left;
                        --right;
                    }
                }    
                else if (res < 0)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            } 
            ++index;
        }
    return ans;
    }
};

int main(void)
{
    vector<int> num{1, 2, 3, 4, 5, 6};
    Solution s;
    vector<vector> > ans(s.threeSum(num));
    for( auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << ", ";    
        }
        cout << endl;
    }
    return 0;
}
