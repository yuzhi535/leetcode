#include <iostream>

#define N 8
#define MAX 10000

using std::cout;
using std::endl;
using std::ends;

int a[N];

void init()
{
    for (int i = 0; i < N; ++i)
        a[i] = MAX;
}

void print()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j == a[i])
                cout << '*' << ends;
            else
            {
                cout << '-' << ends;
            }
        }
        cout << endl;
    }
}

bool valid(int row, int col)
{
    for (int i = 0; i <= row; ++i)
    {
        if (a[i] == col || abs(a[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void EightQueue()
{
    int i, j = 0, index = 0;
    for (i = 0; i < N; ++i)
    {
        for (; j < N; ++j)
        {
            if (valid(i, j))
            {
                a[i] = j;
                j = 0;
                break;
            }
        }
        if (a[i] == MAX)
        {
            if (i == 0)
                break;
            --i;
            j = a[i] + 1;
            a[i] = MAX;
            --i;
            continue;
        }
        if (i == N - 1)
        {
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++\n第" << ++index << "种:" << endl;
            print();
            j = a[i] + 1;
            a[i] = MAX;
            --i;
        }
    }
}

int main(void)
{
    init();
    EightQueue();
    return 0;
}
