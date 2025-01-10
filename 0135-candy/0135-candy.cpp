class Solution {
    public :
    int candy(vector<int> ratings) {
        int n=ratings.size();
        vector<int>left(n,-1);
        left[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
         int cnt=1;
         int sum=0;
         int maxi=left[n-1];
         maxi=max(maxi,cnt);
        sum+=maxi;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cnt=cnt+1;
            }
            else{
                cnt=1;
            }

            maxi=max(cnt,left[i]);
            sum+=maxi;
        }
        return sum;


    }
};