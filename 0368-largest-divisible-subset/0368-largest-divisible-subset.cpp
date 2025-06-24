class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        
        for (int i = 0; i < n; i++) hash[i] = i;

        int maxi = 1;
        int lastind = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastind = i;
            }
        }

        vector<int> ans;
        while (hash[lastind] != lastind) {
            ans.push_back(nums[lastind]);
            lastind = hash[lastind];
        }
        ans.push_back(nums[lastind]); // push the last remaining element

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
