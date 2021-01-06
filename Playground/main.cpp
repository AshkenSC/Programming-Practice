#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 0322. Coin Change
/*
这题实际上给出的是一个直角三角形。只能向下或者向右走。
1）在原点
dp{i]{j] = dp[i][j]
2）只能从上来
dp[i][j] = dp[i - 1][j]
3）只能从左上来
dp[i][j] = dp[i - 1][j - 1]
4）可从左上or上来
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1])


*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }

        vector<vector<int>> dp;
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        }

        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }

                    maxSide = max(dp[i][j], maxSide);
                }
            }
        }

        return maxSide * maxSide;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    Solution sol;
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<char>> input = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int res = sol.maximalSquare(input);
    cout << res;

    return 0;
}