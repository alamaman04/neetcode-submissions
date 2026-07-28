class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q ;
        for(int i =0 ;i< queries.size() ;i++) {
            q.push_back({queries[i],i}) ;
        }
        sort(q.begin(),q.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap ;
        
        int i = 0 ;
        int n = intervals.size() ;
        int m = queries.size() ;

        vector<int>ans(m,-1) ;
        
        for(int j =0 ;j< m;j++){
            int x = q[j].first ;
            int idx = q[j].second ;
            
            while(i<n && intervals[i][0]<=x){
                int len = intervals[i][1]- intervals[i][0] +1 ;
                minHeap.push({len , intervals[i][1]}) ;
                i++ ;
            }
            while(!minHeap.empty() && minHeap.top().second < x){
                minHeap.pop() ;
            }
            if(!minHeap.empty()){
                ans[idx] = minHeap.top().first ;
            }
        }
        return ans ;
    }
};
