class Solution {
public:
    int climbStairs(int n) {
        long long prev=1;
        long long prev2=1;
        long long curr =0;
        for(int i=2;i<n;i++){
            curr = prev+prev2;
            prev2=prev;
            prev=curr;
        }

        return prev;
    }
};