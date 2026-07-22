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
        return rec(0,n-1,nums,memo) ;


    }
};
