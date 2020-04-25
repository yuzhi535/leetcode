#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

constexpr int MAX = 256;

//思路：此算法关注的是参加匹配最末位字符的下一个字符，若没有出现在匹配的字符串中，则直接跳过，即跳过了匹配字符春长度+1的字符了
//这样大大缩短了时间

class Solution
{
private:
    int shift[MAX];
public:
    int isInString(const string& pat, const string& txt)
    {
        int m = pat.size();
        int n = txt.size();
        if (m > n)                     //排除特殊情况
            return 0;
        for (int i = 0; i < MAX; ++i)
            shift[i] = m + 1;          //默认跳过字长
        for (int i = 0; i < m; ++i)
            shift[pat[i]] = m - i;
        int s = 0, j;
        while (s <= n - m)             
        {
            j = 0;
            while (txt[s + j] == pat[j])
                ++j;
            if (j >= m)
                return s + 1;
            s += shift[txt[s + m]];
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    string pat, txt;
    while (getline(cin, pat))
    {
        getline(cin, txt);
        int re = s.isInString(pat, txt);
        if (re)
            cout <<  "匹配的是从左往右数第" << re << "开始" << endl;
        else
            cout << "然而并不匹配" << endl;
    }
    cout << "退出成功" << endl;
    return 0;
}
