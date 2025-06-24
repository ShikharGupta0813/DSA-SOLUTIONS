class Solution {
public:
  int solution(vector<int>&nums,int i,int j,int n,vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][j+1]!=-1) return dp[i][j+1];
    int len=0;
    len=solution(nums,i+1,j,n,dp);
    if(j==-1||nums[i]>nums[j]){
        len=max(len,1+solution(nums,i+1,i,n,dp));
    }
     return dp[i][j+1]=len;
  }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solution(nums,0,-1,nums.size(),dp);
    }
};