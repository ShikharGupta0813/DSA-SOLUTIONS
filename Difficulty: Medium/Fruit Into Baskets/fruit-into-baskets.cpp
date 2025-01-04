//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//Back-end complete function template in C++

class Solution {
  public:
    // Function to find the maximum number of fruits that can be collected without
    // picking any from the third type.
    int totalFruits(vector<int> &arr) {
        int res = 0, cur = 0, count_b = 0, a = 0, b = 0;

        // iterating over each fruit.
        for (int c : arr) {
            // updating cur if fruit is same as a or b, else updating count_b.
            cur = c == a || c == b ? cur + 1 : count_b + 1;
            count_b = c == b ? count_b + 1 : 1;

            // updating a and b if b is not equal to c.
            if (b != c)
                a = b, b = c;

            // calculating the maximum number of fruits that can be collected so far.
            res = max(res, cur);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends