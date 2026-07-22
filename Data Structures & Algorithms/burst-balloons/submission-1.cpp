class Solution {
public:
    int rec(int left ,int right,vector<int>&nums,vector<vector<int>>&memo){
        if(right-left==1) return 0 ;
        if(memo[left][right]!=-1) return memo[left][right] ;
        int ans = INT_MIN ;
        // pick one to be burst in last 
        for(int i= left+1 ;i< right ;i++){
           int cost =  nums[left]*nums[right]*nums[i]+rec(left,i,nums,memo)+rec(i,right,nums,memo);
           ans = max(ans,cost) ;
        }
        return memo[left][right] = ans ;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1) ;
        nums.push_back(1) ;
        int n = nums.size() ;
        vector<vector<int>>memo(n,vector<int>(n,-1));
        //return rec(0,n-1,nums,memo) ;

        // tabulation approach 
        vector<vector<int>>dp(n,vector<int>(n,0)) ;

        for(int i=n-1 ;i>=0 ;i--){
            for(int j=0 ; j<n ;j++){
                if(j-i<=1) continue ;
                dp[i][j] = INT_MIN ;
                for(int k = i+1 ; k<j ;k++){
                    int cost = nums[i]*nums[j]*nums[k]+dp[i][k]+ dp[k][j] ;
                    dp[i][j] = max(dp[i][j] ,cost) ;
                }
            }
        }
        return dp[0][n-1] ;


    }
};
