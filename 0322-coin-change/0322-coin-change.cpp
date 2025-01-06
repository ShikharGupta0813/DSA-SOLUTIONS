class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(),coins.end())  ;  
    int j=coins.size()-1;
    int cnt=0;
   while(j>=0 && amount>0){
    if(coins[j]<=amount){
        amount-=coins[j];
        cnt++;
    }
    else {
        j--;
    }
   }
         return amount==0?cnt:-1;
    }
};