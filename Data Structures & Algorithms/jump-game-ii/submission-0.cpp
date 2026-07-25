class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        int l =0 , r= 0 ;
        int jumps = 0 ;
        
        while(r<n-1){
            jumps++ ;
            int maxreach = r ;
            for(int i=l ;i<= r ;i++){
                maxreach = max(maxreach,nums[i]+i) ;
            }
            l = r+1 ;
            r = maxreach ;
        }
        return jumps ;
    }
};
