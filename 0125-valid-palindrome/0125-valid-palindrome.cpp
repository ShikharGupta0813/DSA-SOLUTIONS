class Solution {
public:
bool pal(string s,int i){
    if(i<0||i==s.length()) return true;
    int first = i;
    int last = s.length()-i-1;
    if(s[first]!=s[last]) return false;
    return pal(s,i+1);
}
    bool isPalindrome(string s) {
        if(s.length()<2) return true;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>'A'&&s[i]<'Z') ans.push_back(tolower(s[i]));
            else if(isalnum(s[i])) continue;
            else ans.push_back(s[i]);
        }
        
        return !pal(ans,0);
    }
};