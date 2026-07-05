class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<>>pq; 
        int ans = INT_MIN;
        int sz = 0 ;
        for(int i=0 ;i<nums.size() ;i++){
            pq.push(nums[i]) ;
            sz++ ;
            if(sz==k) {
                ans = max(ans ,pq.top()) ; pq.pop() ;
                sz-- ;
            }
        }
        return ans ;
    }
};
