class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,0))) ;

        for(int i=n-1 ;i>=0;i--){
            // holding 
            // skip 
            dp[i][1][0] = dp[i+1][1][0] ;
            dp[i][1][1] = dp[i+1][1][1] ;
            // sell 
            dp[i][1][0] = max(dp[i][1][0],prices[i]+dp[i+1][0][0]) ;
            dp[i][1][1]= max(dp[i][1][1] ,prices[i]+dp[i+1][0][0]) ;

            // not holding 
            //skip
            dp[i][0][0] = dp[i+1][0][1] ;
            dp[i][0][1] = dp[i+1][0][1];
            // buy 
            dp[i][0][1] = max(dp[i][0][1],-prices[i]+dp[i+1][1][1]) ;
            dp[i][0][1] = max(dp[i][0][1],-prices[i]+dp[i+1][1][0]) ;
        }

        return dp[0][0][1] ;

    }
};
