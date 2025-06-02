class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,m,n,dp);
    }
    int helper(int i,int j,int n,int m,vector<vector<int>>dp){
        if(i==0&&j==0) return 1;
        if(i<0||i>n-1||j<0||j>m-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i-1,j,n,m,dp);
        int left =helper(i,j-1,n,m,dp);
        return dp[i][j] =up + left;
    }
};