class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,m,n,dp);
    }
    int helper(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i-1,j,n,m,dp);
        int left =helper(i,j-1,n,m,dp);
        return dp[i][j] =up + left;
    }
};

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return helper(m-1,n-1,m,n,dp);
//     }
//     int helper(int i,int j,int n,int m,vector<vector<int>>dp){
//         if(i==0&&j==0) return 1;
//         dp[0][0]=1;
//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//              int up = dp[i-1][j]
//              int left = dp[i][j-1]
//             }
//         }
       
//         return dp[n-1][m-1] 
//     }
// };