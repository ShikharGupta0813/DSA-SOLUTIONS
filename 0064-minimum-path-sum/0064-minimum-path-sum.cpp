// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//          int n=grid.size();
//         int m =grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return helper(n-1,m-1,grid,dp);
//     }
//     int helper(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
//        if(n==0&&m==0) return grid[0][0];
//        if(n<0||m<0)return 1e8;
//        if(dp[n][m]!=-1) return dp[n][m];
//        int up = grid[n][m]+helper(n-1,m,grid,dp);
//        int left = grid[n][m]+helper(n,m-1,grid,dp);

//        return dp[n][m]= min(up,left);

//     }
// };

class Solution{
    public:

    int minPathSum(vector<vector<int>>grid){

        int n =grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int up=0,left=0;
                if(i==0&&j==0) continue;
               if(i>0)  up=grid[i][j]+dp[i-1][j];
               if(j>0)  left=grid[i][j]+dp[i][j-1];
             
               dp[i][j]= min(up,left);
                  
            }
        }
        return dp[n-1][m-1];
    }
};