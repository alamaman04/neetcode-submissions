class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size() ;

        if(n==1) return 0 ;
  
        int prevEnd = intervals[0][1] ;

        int cnt = 0 ;
        for(int i=1 ;i<n;i++){
            if(intervals[i][0]< prevEnd){ // overlaps
                prevEnd = min(prevEnd,intervals[i][1]);
                cnt++ ;
            }else{
                prevEnd = intervals[i][1] ;
            }
        }
        return cnt ;
    }
};
