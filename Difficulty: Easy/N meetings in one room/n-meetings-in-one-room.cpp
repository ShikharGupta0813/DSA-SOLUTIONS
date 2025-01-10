//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  static bool comparator(vector<int>a,vector<int>b){
            return a[1]<b[1] ;
            
        }
  
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>> ans;
        for(int i=0;i<start.size();i++){
            ans.push_back({start[i],end[i]});
        }
        
      // Sort meetings based on end time
       sort(ans.begin(), ans.end(), comparator);
     
     int last=ans[0][1];
     int cnt=1;
     for(int i=1;i<start.size();i++){
         if(ans[i][0]>last){
             cnt++;
             last=ans[i][1];
         }
     }
     return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends