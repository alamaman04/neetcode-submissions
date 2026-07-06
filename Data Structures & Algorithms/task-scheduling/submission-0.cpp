class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26) ;
        for(auto ch : tasks){
            freq[ch-'A'] ++ ;
        }
        priority_queue<pair<int,int>>pq ;
        for(int i=0 ;i<26 ;i++){
            if(freq[i]) pq.push({freq[i],i}) ;
        }
        queue<pair<int,int>>q ;
        int time = 0 ;
        while(!pq.empty() || !q.empty()){
            // insert waiting task from q 
            if(!q.empty() && q.front().first ==time){
                pq.push({freq[q.front().second],q.front().second});
                q.pop() ;
            }
            if(!pq.empty()){
                auto p = pq.top() ;pq.pop() ;
                freq[p.second]-- ;
                if(freq[p.second]) q.push({time+n+1,p.second});
            }
            time++ ;
        }
        return time ;
    }
};
