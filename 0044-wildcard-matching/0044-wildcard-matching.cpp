class Solution {
public:
   bool f(string s,string p ,int i,int j){
     if (i < 0 && j < 0) return true; // both strings finished
        if (j < 0 && i >= 0) return false; // pattern empty but s not
        if (i < 0 && j >= 0) {
            // check if remaining pattern is all '*'
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

    if(s[i]==p[j] || p[j]=='?'){
       return f(s,p,i-1,j-1);
    }
    else if(p[j]=='*'){
       return f(s,p,i,j-1)||f(s,p,i-1,j);
    }
    else return false;
   }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return f(s,p,n-1,m-1);
    }
};