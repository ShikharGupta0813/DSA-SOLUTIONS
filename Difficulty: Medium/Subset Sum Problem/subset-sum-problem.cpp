class Solution {
  public:
  
   bool f(vector<int>&arr,int sum,int i){
       if(sum==0) return true;
       if(i==arr.size()) return false;
       
       
       if(arr[i]<=sum){
           return f(arr,sum-arr[i],i+1)||f(arr,sum,i+1);
       }
       
       return f(arr,sum,i+1);
       
   }
   
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        return f(arr,sum,0);
    }
};