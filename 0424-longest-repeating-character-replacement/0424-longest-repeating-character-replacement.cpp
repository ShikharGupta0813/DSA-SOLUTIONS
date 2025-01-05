class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs;
        int res = 0, i = 0, maxFreq = 0;

        for (int j = 0; j < s.size(); j++) {
            freqs[s[j]]++;
            maxFreq = max(maxFreq, freqs[s[j]]);

            if ((j - i + 1) - maxFreq > k) {
                freqs[s[i]]--;
                i++;
            }
            if((j - i + 1) - maxFreq <= k)
            res = max(res, j - i + 1);
        }

        return res;
    }
};