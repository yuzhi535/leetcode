#include <iostream>
#include <unordered_map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;


class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> ans;
        int left = 0, right = left, length = 0, result = 0;
        unordered_map<char, int>::iterator i;
        while (right < s.size())
        {
            i = ans.find(s[right]);
            if (i != ans.end() && i->second >= left)
            {
                left = i->second + 1;
                length = right - left;
            }
            ++length;
            ans[s[right]] = right;
            ++right;
            result = max(result, length);
        }
        return result;
    }
};

int main(void)
{
    string s;
    getline(cin, s);
    Solution ss;
    cout << ss.lengthOfLongestSubstring(s) << endl;;
    return 0;
}
