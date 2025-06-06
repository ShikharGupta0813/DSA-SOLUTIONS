class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum =0;

        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        if(sum%2!=0) return false;

        return helper(n-1,sum/2,nums);
    }

     bool helper(int i,int sum,vector<int>&nums){
        if(sum==0)return true;
        if(i==0 && nums[0]==sum) return true;
        if(i==0) return false;
        
        bool notake=helper(i-1,sum,nums);
        bool take =false;
        if(sum>nums[i]){
             take=helper(i-1,sum-nums[i],nums);
        }
        return take||notake;

     }

};