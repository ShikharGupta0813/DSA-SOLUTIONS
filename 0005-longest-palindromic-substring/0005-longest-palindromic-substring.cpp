class Solution {
public:
    string longestPalindrome(string s) {
       string ans="",ans2="";int cnt=0;int lst=s.length()-1;
    for(int str=0;str<=lst;str++){
    for(int i=lst;i>=0;i--){
        int n=str,m=i;
     while(str<=i){
        if(s[str]!=s[i]){
             break;
        }
        str++;i--;
     } str=n;i=m;
     if(str>=i&&cnt==0){ans =s.substr(n,(m-n+1));cnt++;}
     else if(str>=i&&cnt==1){ans2=s.substr(n,(m-n+1));
           ans=max(ans.length(),ans2.length());}
    }
     }
         return ans;
    }
};