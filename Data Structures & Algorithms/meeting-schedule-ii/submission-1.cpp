/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size() ;
       
       vector<int>start(n),end(n) ;
       for(int i=0 ;i<n ;i++){
            start[i] = intervals[i].start ;
            end[i] = intervals[i].end ;
       }
       sort(start.begin() ,start.end()) ;
       sort(end.begin() ,end.end()) ;

       int l = 0, r = 0 ;

       int cnt = 0 ;
       int ans = 0 ;
       while( l < n ){
          if(l<n && start[l] < end[r]) {
             l++;
             cnt++ ;
          }else {
            cnt-- ;
            r++ ;
          }
          ans = max(ans ,cnt) ;
       }

    return ans ;

    }
};
