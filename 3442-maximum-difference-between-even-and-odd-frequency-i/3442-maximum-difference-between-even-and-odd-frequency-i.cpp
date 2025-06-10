class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        int odd=0,even=0;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for (auto& it : mp) {
    if (it.second % 2 == 0) {
        even = max(even, it.second);
    } else {
        odd = max(odd, it.second);
    }
}
       
     return (odd-even) ;
    }
};