#include <bits/stdc++.h>

using namespace std;
#define N 32001

struct Row
{
    int l, r;
    bool operator< (Row other) const
    {
        if (r < other.r)
            return true;
        else if (r == other.r)
            if (l < other.l)
                return true;
        return false;
    }
} row[N];

//

int main()
{
    int n;
    int count = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> row[i].l >> row[i].r;
        row[i].r += row[i].l;
    }
    sort(row, row + n);
    for (int i = 1, j = 0; i < n; ++i)
    {
        if (row[j].r <= row[i].l)
        {
            j = i;
            ++count;
        }
    }
    cout << count;
    return 0;
}
