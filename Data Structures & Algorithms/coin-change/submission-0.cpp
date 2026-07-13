class Solution {
public:
    // int rec(int idx , int amount , vector<int>& coins){
    //     // base case 
    //     if(amount ==0) return 0 ;
    //     if(idx == coins.size())return INT_MAX ;
        
    //     if(memo[idx][amount]!=-1) return memo[idx][amount] ;

    //     int coins = 0 ;
    //     // not take 
    //     int not_take = rec(idx)
        
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<vector<int>>dp(n+1, vector<int>(amount+1,1e9)) ;
        for(int i=0 ;i<=n ;i++) dp[i][0] = 0 ;
        
        for(int i=1 ;i<= n; i++){
            for(int j =1 ;j<= amount ;j++){
                // not take 
                dp[i][j] = dp[i-1][j] ;
                // take 
              if(coins[i-1]<= j)  dp[i][j] = min(dp[i][j] , 1+ dp[i][j-coins[i-1]]) ;
            }
        }
        if(dp[n][amount]==1e9) return -1 ;
        return dp[n][amount] ;
    }
};
