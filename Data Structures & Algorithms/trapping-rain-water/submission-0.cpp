class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int leftmax = 0 , rightmax = 0 ;
        int l= 0 , r = n-1 ;

        int ans =0;
        while(l<=r){
            if(leftmax < rightmax){ // height at i determined by leftmax 
            // process the left pointer 
                leftmax = max(leftmax,height[l]) ;
                ans +=  leftmax-height[l] ;
                l++ ;
            }
            else {
                rightmax = max(rightmax,height[r]) ;
                ans += rightmax- height[r] ;
                r-- ;
            }
        }
        return ans ;
    }
};
