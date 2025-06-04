class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 1e8;

        for (int j = 0; j < m; j++) {
            ans = min(ans, helper(n - 1, j, matrix, dp));
        }
        return ans;
    }

    int helper(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp) {
        int m = a[0].size();
        if (j < 0 || j >= m) return 1e8;        // ✅ check bounds first
        if (i == 0) return a[0][j];             // base case
        if (dp[i][j] != -1) return dp[i][j];    // memoization

        int up = a[i][j] + helper(i - 1, j, a, dp);
        int leftDiag = a[i][j] + helper(i - 1, j - 1, a, dp);
        int rightDiag = a[i][j] + helper(i - 1, j + 1, a, dp);

        return dp[i][j] = min({up, leftDiag, rightDiag});
    }
};
