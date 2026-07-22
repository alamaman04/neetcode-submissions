class Solution {
public:
    
    int rec(int i , int j, string& s , string &t,vector<vector<int>>& memo){
        if(i==s.size()){
            if(j==t.size()) return 1 ;
            return 0 ;
        }
        if(memo[i][j]!= -1) return memo[i][j] ;

        int distinct = 0 ;
        if(s[i]==t[j]) distinct+= rec(i+1,j+1,s,t,memo) ;
        distinct+= rec(i+1,j,s,t,memo) ;
        return memo[i][j] = distinct ;
    }
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        if(n<m) return 0 ;
        vector<vector<int>>memo(n,vector<int>(n,-1)) ;
        //return rec(0,0,s,t,memo) ;

        // tabulation 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)) ;
        // for(int i=0 ;i<=n ;i++) dp[i][m] = 1 ;// base case 
        // for(int i=n-1 ;i>=0 ;i--){
        //     for(int j=m-1;j>=0 ;j--){
        //         dp[i][j]+= dp[i+1][j] ;
        //         if(s[i]==t[j]) dp[i][j] += dp[i+1][j+1] ;
        //     }
        // }
        // return dp[0][0] ;

        // i can also do
        for(int i=0;i<=n;i++) dp[i][0] = 1 ;
        for(int i=1 ;i<=n; i++){
            for(int j=1 ;j<=m ;j++){
                dp[i][j] += dp[i-1][j] ;
                if(s[i-1]==t[j-1])dp[i][j]+= dp[i-1][j-1] ;
            }
        }
        return dp[n][m] ;



    }
};
