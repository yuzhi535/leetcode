#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::vector;


class Solution {
public:
    int countSquares(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > f(m, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    f[i][j] = matrix[i][j];
                }
                else if (matrix[i][j] == 0) {
                    f[i][j] = 0;
                }
                else {
                    f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
                }
                ans += f[i][j];
            }
        }
        return ans;
    }
};


int main(void)
{
    vector<vector<int> > s{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    Solution ans;
    cout << ans.countSquares(s);
    return 0;
}
