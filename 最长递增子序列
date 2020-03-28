#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

//最长递增子序列


class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 2)
            return 1;
        vector<int> ans(1, 0);
        ans[0] = nums[0];
        int len = 1;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (ans[len - 1] < nums[i])
            {
                ans.push_back(nums[i]);
                ++len;
            }
            else
            {
                int left = 0, right = ans.size();
                while (left < right)
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



int main(void)
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    Solution s;
    cout << s.lengthOfLIS(num) << endl;
    return 0;
}
