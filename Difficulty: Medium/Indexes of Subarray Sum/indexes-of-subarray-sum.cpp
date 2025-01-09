//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
vector<int> subarraySum(vector<int> arr, int target) {
    vector<int> res;
    int n = arr.size();

    // Pick a starting point for a subarray
    for (int s = 0; s < n; s++) {
        int curr = 0;
      	
        // Consider all ending points
        // for the picked starting point 
        for (int e = s; e < n; e++) {
            curr += arr[e];
            if (curr == target) {
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
  	// If no subarray is found
    return {-1}; 
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends