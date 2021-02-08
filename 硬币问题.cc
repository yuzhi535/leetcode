#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


//硬币问题
//
class Solution
{
public:
    int mincoin(vector<int>& coin, int target)
    {
        vector<int> temp(target + 1, target + 1);
        temp[0] = 0;
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < coin.size(); ++j)
            {
                if (i - coin[j] < 0) continue;
                temp[i] = min(temp[i], temp[i - coin[j]] + 1);
            }
        }
        if (temp[target] == target + 1)
            return -1;
        return temp[target];
    }
};



int main(void)
{
    vector<int> coin{ 1, 2, 3, 7 ,8 };
    Solution s;
    cout << s.mincoin(coin, 15) << endl;
    return 0;
}
