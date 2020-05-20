#include <bits/stdc++.h>

#define MAX 200001

using namespace std;
using ll = long long;

ll num[MAX];

int main(void)
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> num[i];
            num[i] = num[i] + num[i - 1];
        }    
        ll m_max = -1e18, ans = -1e18;
        for (int i = k; i <= n - k ; ++i)
        {
            m_max = max(m_max, num[i] - num[i - k]);
            ans = max(ans, m_max + num[i + k] - num[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
