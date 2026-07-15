class Solution {
public:

     vector<vector<int>>memo ;
    
    // recursive solution 
    // int rec(int idx , int holding , vector<int>&prices){
    //     if(idx>= prices.size()) return 0 ;
    //     if(memo[idx][holding]!=-1 ) return memo[idx][holding];
    //     int profit = 0 ;

    //     if(!holding){
    //        profit = max(profit,rec(idx+1,holding,prices)) ; // skipped
    //        profit = max(profit,-prices[idx]+rec(idx+1,1,prices)); // buy  
    //     }
    //     else{
    //         profit = max(profit,rec(idx+1,true,prices)) ; // skipped
    //         profit = max(profit , prices[idx]+rec(idx+2,false,prices)) ; // sell
    //     }
    //     return memo[idx][holding] = profit ;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        // memo.assign(n+1,vector<int>(2,-1));
        // return rec(0,0,prices) ;



        //vector<vector<int>>dp(n+2,vector<int>(2,0)) ; 
        // top down dp
        // dp[i][h] = max profit if i start at day i with holding h ;
        // for(int i=n-1 ;i>=0;i--){
        //     // holding 
        //     dp[i][1] = dp[i+1][1] ;
        //     // sell 
        //     dp[i][1] = max(dp[i][1],prices[i]+dp[i+2][0]) ;


        //     // not holding 
           
        //     dp[i][0] = dp[i+1][0] ; //skip
        //     dp[i][0] = max(dp[i][0],-prices[i]+dp[i+1][1]) ;  // buy 
        // }
        // return dp[0][0] ;

        // optimised 
        int dp1_buy = 0, dp1_sell =0 , dp2_buy =0;

        for(int i=n-1 ;i>=0 ;i--){
           int ndp1_sell = max(dp1_sell, prices[i]+dp2_buy) ;
            int ndp1_buy = max(dp1_buy,-prices[i]+dp1_sell) ;
            dp2_buy = dp1_buy ;
            dp1_buy = ndp1_buy ;
            dp1_sell = ndp1_sell ;
        }
        return dp1_buy ;
    }
};
