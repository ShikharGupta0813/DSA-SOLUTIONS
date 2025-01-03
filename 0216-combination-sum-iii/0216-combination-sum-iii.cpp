class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>ds;
        helper(k,n,1,result,ds);
        return result;
    }

    void helper(int k, int n, int value, vector<vector<int>>& combinations,
            vector<int> combination) {
        int combinationSize = combination.size();

        if (combinationSize == k && n == 0) {
            combinations.push_back(combination);
            
            return;
        }

        for (int i = value; i < 10; i++) {
            if (combinationSize > k || n < 0)
                break;

            combination.push_back(i);

            helper(k, n - i, i + 1, combinations, combination);

            combination.pop_back();
        }
    }
};

