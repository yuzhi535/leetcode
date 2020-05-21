#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dp[16];
int row, col, k;
ll arr[16][16], dRow[16], dCol[16];

int countRow(ll x)
{
    memset(dp, 0, 16);
    if (!x)
        return 0;
    int i = 1, count = 0;
    while (x)
    {
        if (x & 1)
        {
            dp[i] = 1;
            ++count;
        }
        x >>= 1;
        ++i;
    }
    return count;
}


int main()
{
    //接受数字
    ll sum, ans = 0;
    cin >> row >> col >> k;
    if (k > row)
        k = row;
    if (k > col)
        k = col;
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
        {
            cin >> arr[i][j];
            dRow[i] += arr[i][j];
        }

    //先枚举所有行，然后在各自基础上枚举列
    ll tmp = 1 << row;
    for (int i = 0; i < tmp; ++i)              //以二进制后的数字进行
    {
        sum = 0;
        int re = countRow(i);
        int tl = k - re;
        if (tl > col || tl < 0)
            continue;

        for (int j = 1; j <= row; ++j)
        {
            if (dp[j])
                sum += dRow[j];
        }
        memset(dCol, 0, sizeof(dCol));

        for (int j = 1; j <= row; ++j)
            for (int item = 1; item <= col; ++item)
                if (!dp[j])
                    dCol[item] += arr[j][item];
        sort(dCol + 1, dCol + col + 1);
        for (int j = col; j > col - tl; --j)
            sum += dCol[j];
        ans = max(ans, sum);
        memset(dp, 0, sizeof(dp));
    }

    cout << ans;

    return 0;
}
