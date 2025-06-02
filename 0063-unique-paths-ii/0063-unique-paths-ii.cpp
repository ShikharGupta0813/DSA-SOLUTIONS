class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,m,n,dp,obstacleGrid);
    }
    int helper(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>&a){
        
         if((i==0&&j==0)&&(a[i][j]!=1)) return 1;
         if((i<0||j<0)||(a[i][j]==1)) return 0;
        
         if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i-1,j,n,m,dp,a);
        int left =helper(i,j-1,n,m,dp,a);
         return dp[i][j] =up + left;
    }
};