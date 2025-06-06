class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(n - 1, target, nums, dp);
    }

    bool helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (i == 0) return nums[0] == sum;
        if (dp[i][sum] != -1) return dp[i][sum];

        bool notTake = helper(i - 1, sum, nums, dp);
        bool take = false;
        if (sum >= nums[i])
            take = helper(i - 1, sum - nums[i], nums, dp);

        return dp[i][sum] = take || notTake;
    }
};
