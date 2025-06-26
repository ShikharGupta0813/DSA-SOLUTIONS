class Solution {
public:
    int f(string word1,string word2,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(word1[i]==word2[j]) return 0+ f(word1,word2,i-1,j-1);
        return min(1+f(word1,word2,i-1,j-1),min(1+f(word1,word2,i,j-1),1+f(word1,word2,i-1,j)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // if(n==0&&m==0) return 0;
        return f(word1,word2,n-1,m-1);
    }
};