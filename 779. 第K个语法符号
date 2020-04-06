//递归写法，比较简单
//奇偶分开就足够了
class Solution {     
public:
    int kthGrammar(int N, int K) {
        if (N == 1)
        {
            return 0;
        }
        else if (N == 2)
        {
            if (K == 1)
                return 0;
            return 1;
        }
        else
        {
            if (K % 2)
            {
                return kthGrammar(N - 1, (K + 1) / 2);
            }
            else
            {
                return !kthGrammar(N - 1, K / 2);
            }
        }
    }
};
