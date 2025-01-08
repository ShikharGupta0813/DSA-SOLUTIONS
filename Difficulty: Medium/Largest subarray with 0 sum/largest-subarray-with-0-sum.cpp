//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
public:
    int maxLen(vector<int>& arr) {
       
       unordered_map<int, int> prefixSum; // Map to store sum and index
        int sum = 0; // Cumulative sum
        int maxlen = 0; // Maximum length of subarray

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If sum is zero, the subarray from the start to i has sum zero
            if (sum == 0) {
                maxlen = i + 1;
            }

            // If sum is already seen, calculate the length of subarray
            if (prefixSum.find(sum) != prefixSum.end()) {
                maxlen = max(maxlen, i - prefixSum[sum]);
            } else {
                // Otherwise, store the sum with the current index
                prefixSum[sum] = i;
            }
        }

        return maxlen;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends