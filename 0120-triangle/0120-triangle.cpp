class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(0,0,triangle,n,m,dp);
    }
    int helper (int i,int j,vector<vector<int>>&a,int n,int m,vector<vector<int>>&dp){

        if(i==n-1)return a[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = a[i][j]+helper(i+1,j,a,n,m);
        int diagonal = a[i][j]+helper(i+1,j+1,a,n,m);

        return dp[i][j]= min(down,diagonal);


        
    }
};