class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size() ;
       int lo = 0 , hi = n-1 ;

       while(lo < hi){
            int mid = (lo+hi)/2 ;
            if(nums[mid] > nums[hi]) lo = mid+1 ;
            else hi = mid ;
       }
       // lo is the pivot

       auto search = [&](int l , int h){
           while(l<=h){
              int mid = (l+h)/2 ;
              if(nums[mid]==target) return mid ;
              else if(nums[mid]> target) h = mid-1 ;
              else l = mid+1 ;
           }
           return -1 ;
       };

       int ans = search(0,lo-1) ;
       if(ans==-1) ans =search(lo,n-1) ;
       return ans;
        
    }
};
