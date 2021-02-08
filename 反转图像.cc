//这没的说，就是考细心程度，照着题目做就行了
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        unsigned i = 0;
        while (i < matrix.size() / 2)
        {
            for (unsigned j = i; j < matrix.size() - i - 1; ++j)
                {int ten = matrix[j][matrix.size() - 1 - i]; matrix[j][matrix.size() - 1- i] = matrix[i][j]; matrix[i][j] = ten; }
            for (unsigned j = i; j < matrix.size() - i - 1; ++j)
                {int ten = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j]; matrix[matrix.size() - 1 - i][matrix.size() - 1-  j] = matrix[i][j]; matrix[i][j] = ten; }
            for (unsigned j = i; j < matrix.size() - i - 1; ++j)
                {int ten = matrix[matrix.size() - 1 - j][i]; matrix[matrix.size() - 1 - j][i] = matrix[i][j]; matrix[i][j] = ten; }
            ++i;
        }

    }
};
