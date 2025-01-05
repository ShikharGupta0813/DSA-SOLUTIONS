class Solution {
    int helper(int start, int n, vector<int>& nums, vector<int>& dp) {
        if (n<start) {
            return 0; // No house to rob
        }
        if(start==n){
            return nums[n];
        }
        if (dp[n] != -1) {
            return dp[n]; // Return already computed value
        }

        // Rob the current house and skip one, or skip the current house
        int rob = nums[n] + helper(start, n-2, nums, dp);
        int skip = helper(start, n-1, nums, dp);

        return dp[n] = max(rob, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Edge case: Only one house

        // Exclude the last house
        vector<int> dp1(n, -1);
        int excludeLast = helper(0, n - 2, nums, dp1);

        // Exclude the first house
        vector<int> dp2(n, -1);
        int excludeFirst = helper(1, n - 1, nums, dp2);

        return max(excludeLast, excludeFirst);
    }
};
