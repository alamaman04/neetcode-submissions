class Solution {
public:

     vector<vector<int>>memo ;
    
    // recursive solution 
    int rec(int idx , int holding , vector<int>&prices){
        if(idx>= prices.size()) return 0 ;
        if(memo[idx][holding]!=-1 ) return memo[idx][holding];
        int profit = 0 ;

        if(!holding){
           profit = max(profit,rec(idx+1,holding,prices)) ; // skipped
           profit = max(profit,-prices[idx]+rec(idx+1,1,prices)); // buy  
        }
        else{
            profit = max(profit,rec(idx+1,true,prices)) ; // skipped
            profit = max(profit , prices[idx]+rec(idx+2,false,prices)) ; // sell
        }
        return memo[idx][holding] = profit ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        memo.assign(n+1,vector<int>(2,-1));
        return rec(0,0,prices) ;



        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,0))) ;

        // for(int i=n-1 ;i>=0;i--){
        //     // holding 
        //     // skip 
        //     //dp[i][1][0] = dp[i+1][1][0] ;
        //     dp[i][1][1] = dp[i+1][1][1] ;
        //     // sell 
        //     dp[i][1][0] = max(dp[i][1][0],prices[i]+dp[i+1][0][0]) ;
        //     dp[i][1][1]= max(dp[i][1][1] ,prices[i]+dp[i+1][0][0]) ;

        //     // not holding 
        //     //skip
        //     dp[i][0][0] = dp[i+1][0][1] ;
        //     dp[i][0][1] = dp[i+1][0][1];
        //     // buy 
        //     dp[i][0][1] = max(dp[i][0][1],-prices[i]+dp[i+1][1][1]) ;
        //    // dp[i][0][1] = max(dp[i][0][1],-prices[i]+dp[i+1][1][0]) ;
        // }

        // return dp[0][0][1] ;

    }
};
