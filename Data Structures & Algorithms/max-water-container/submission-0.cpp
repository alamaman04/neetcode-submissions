class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() ;
        int l = 0 , r = n-1 ;
        int ans = INT_MIN ;

        while(l<r){
            ans = max(ans , min(heights[l],heights[r])*(r-l)) ;
            if(heights[l]>heights[r]) r-- ;
            else l++ ;
        }
        return ans ;

    }
};
