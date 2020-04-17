#include <cstdio>
#include <cmath>
#include <algorithm>

using std::max;
using std::min;

int tmp;
int cf(int a, int b)            //对于a排除a和b共有的因数
{
    tmp = sqrt(b);
    for (int i = 2; i <= tmp; i++) 
    {
        if (b % i == 0)
            while (a % i == 0)
                a /= i; 
        while (b % i == 0)
            b /= i;
    }
    if (b != 1)
        while (a % b == 0)
            a /= b; 
    return a;      
}

int gcd(int a, int b)           //求最大公因数
{
    return b == 0 ? a : gcd(b, a % b); 
}

//x=p*a1, b1=x*t 所以pt=b1/a1
//满足条件只需要gcd(x/a1,a0/a1)=1且gcd(b1/x,b1/b0)=1即可。即gcd(p,a0/a1)和gcd(t,b1/b0）等于1即可，因此，只需要求出b1/a1的因数再带入判断
//考虑到上式中可能依然有公因数，会有多余的判断，所以需要化简b1/a1，全部消去与a0/a1,b1/b0 有关的因数即可

int main()
{
    int a0, a1, b0, b1;
    int index;
    int m, n, s, l, q;
    scanf("%d", &index);
    int cnt;
    while (index--)
    {
        scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
        if (a0 % a1 | b1 % b0 | b1 % a1)
        {
            printf("0\n"); 
            continue;
        }
        m = a0 / a1, n = b1 / b0, s = b1 / a1;
        l = cf(s, n); 
        if (gcd(max(s / l, m), min(s / l, m)) != 1)
        {
            printf("0\n"); 
            continue;
        }
        q = cf(l, m);
        cnt = 0, tmp = sqrt(q); 
        for (int i = 1; i <= tmp; ++i)
            if (q % i == 0)
                cnt += i == q / i ? 1 : 2;              /考虑对应的因数
        printf("%d\n", cnt);               
    }
    return 0;
}
