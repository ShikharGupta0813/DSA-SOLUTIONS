class Solution {
    int helper(int start, int end, vector<int>& nums, vector<int>& dp) {
        if (start > end) {
            return 0; // No house to rob
        }
        if(start==end){
            return nums[end];
        }
        if (dp[start] != -1) {
            return dp[start]; // Return already computed value
        }

        // Rob the current house and skip one, or skip the current house
        int rob = nums[start] + helper(start + 2, end, nums, dp);
        int skip = helper(start + 1, end, nums, dp);

        return dp[start] = max(rob, skip);
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
