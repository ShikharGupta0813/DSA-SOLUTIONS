class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        int i=0;

        while(i<s.size() && j<g.size()){
            if(g[j]<=s[i]){
                j++;
            }
            i++;
        }

        return j;
    }
};