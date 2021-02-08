#include <algorithm>  
#include <iostream> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <string> 
using namespace std; 
struct info 
{ 
    int l,r,k; 
}num[1001];
inline bool cmp(const info &a,const info &b) 
{ 
    return a.k<b.k; 
} 
int f[20000]; 
int i,j,k,l,m,n,t;
int main() 
{ 
    scanf("%d",&n); 
    for(i=0;i<=n;i++) 
    { 
        scanf("%d%d",&num[i].l,&num[i].r); 
        num[i].k=num[i].r*num[i].l; 
    } 
    sort(num+1,num+n+1,cmp); 
    f[1]=num[0].l;f[0]=1; 
    for (int i=1;i<=n-1;i++) 
    { 
       t=0; 
        for(int j=1;j<=f[0];j++) 
        { 
            f[j]*=num[i].l;f[j]+=t;  
            t=f[j]/10000;f[j]%=10000; 
        } 
        if(t>0)
        {
            f[++f[0]]=t;
        }
    }
    t=0;
    for (int i=f[0];i>=1;i--) 
    { 
        t+=f[i];f[i]=t/num[n].r;
        t%=num[n].r;
        t*=10000;
    }
    for (;f[f[0]]==0 && f[0]>0;f[0]--);
    
    if (f[f[0]]==0)
    {
        printf("1");
    }
    else
    {
        printf("%d",f[f[0]]);
    }
    
    for (int i=f[0]-1;i>=1;i--) 
    {
        if (f[i]<10)
        {
            printf("000");
        }
        if (f[i]<100 && f[i]>=10)
        {
            printf("00");
        }
        if (f[i]<1000 && f[i]>=100)
        {
            printf("0");
        }
        printf("%d",f[i]);
    }
}
