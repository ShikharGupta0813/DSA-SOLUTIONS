class Solution {
public:
  static bool compare(string s1,string s2){
      return  s1.length()<s2.length();
    }
    bool isValid(vector<string>words,int k,int l){
      string s1=words[k];
      string s2=words[l];
      
      int i=0;int j=0;
      while(i!=s1.size()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            i++;
        }
      }
      if(j!=s2.size()) return false;
      return true;

    }

    int f(vector<string>&words,int n,int i,int j){
    int len=1;
    if(i==n)return 0;
    
    len=f(words,n,i+1,j);

    if(j==-1||isValid(words,i,j)){
        len=max(len,1+f(words,n,i+1,i));
    }

    return len;

    } 
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        return f(words,words.size(),0,-1);
    }
};