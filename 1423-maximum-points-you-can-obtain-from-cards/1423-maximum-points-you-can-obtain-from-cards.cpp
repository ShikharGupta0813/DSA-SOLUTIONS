class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); 
        int maxlen = INT_MIN;
        int lsum = 0;
        for(int i=0;i<k;i++){
            lsum = cardPoints[i] + lsum;
        }
        maxlen = lsum;
        int zsum =0;
        int index = n-1;
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];    
            zsum += cardPoints[n - 1 - i];   
            maxlen = max(maxlen, lsum + zsum);
        }
        return maxlen;
    }
};