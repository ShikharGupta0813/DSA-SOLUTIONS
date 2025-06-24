class Solution {
public:

int f(string text1, string text2,int i,int j){
   if(i<0||j<0) return 0;

    if(text1[i]==text2[j]){
    return 1+f(text1,text2,i-1,j-1);
    }
    return max(f(text1,text2,i-1,j),f(text1,text2,i,j-1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return f(text1,text2,text1.length()-1,text2.length()-1);
    }
};