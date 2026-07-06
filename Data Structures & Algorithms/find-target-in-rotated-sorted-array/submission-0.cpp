class Solution {
public:
    int search(vector<int>& nums, int target) {
        // finding deflection point 
        int n = nums.size();
        int def = -1 ;
        int low = 0 , high = n-1 ;
        while(low<high){
            int mid = (low+high) /2 ;
            if(nums[mid]>nums[high]) low = mid+1 ;
            else high = mid ;
        }
        def = low ;

        // check in before deflection 
        low = 0 , high = def-1 ;
        while(low<= high){
            int mid = (low+high) /2 ;
            if(nums[mid]==target) return mid ;
            else if(nums[mid]>target) high= mid-1; 
            else low = mid+1 ;
        }
        // check after deflection 
        low = def , high = n-1; 
         while(low<= high){
            int mid = (low+high) /2 ;
            if(nums[mid]==target) return mid ;
            else if(nums[mid]>target) high= mid-1; 
            else low = mid+1 ;
        }
        return -1 ;
    }
};
