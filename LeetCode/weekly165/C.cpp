// URL: https://leetcode.com/contest/weekly-contest-165/problems/count-square-submatrices-with-all-ones/
// TYPE: DP

class Solution {
public:
    vector<vector<int>> m;

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix;

        //  max side length of submatrix at   y, x
        int dp[matrix.size()][matrix[0].size()] = {};
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                if (matrix[y][x] == 1) {
                    dp[y][x] = 1;
                }
            }
        }

        for (int y = 1; y < matrix.size(); ++y) {
            for (int x = 1; x < matrix[0].size(); ++x) {
                if (dp[y][x]) {
                    dp[y][x] += min({dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]});
                }
            }
        }

        int total = 0;
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                total += dp[y][x];
                cout << dp[y][x] << ' ';
            }
            cout << '\n';
        }
        return total;
    }
};
