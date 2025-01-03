class Solution {

 int helper(int ind,vector<int>nums){
        if(ind<0) return 0;
        if(ind==0){
            return nums[0];
        }
        int left = helper(ind-2,nums)+nums[ind];
        int right = helper(ind-1,nums)+0;
      
        return max(left,right);

    }

public:
    int rob(vector<int>& nums) {
       return helper(nums.size()-1,nums);
    }
   
};