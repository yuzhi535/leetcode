#include <bits/stdc++.h>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        
        std::unordered_map<int, int> intmap;
        for (int i = 0 ; i < length; ++i) {
            intmap[nums[i]] = i;
        }
        
        for (int i = 0; i < length; ++i) {
            int other = target - nums[i];
            if (intmap.count(other) && intmap[other] != i) {
                return vector<int>{i, intmap[other]};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{12, 23, 34, 354, 5};
    auto re = s.twoSum(nums, 35);
    for (auto i : re) {
        printf("%d\t", i);
    }
    
    return 0;
}