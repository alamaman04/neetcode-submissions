class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // start from anyw
        // brutre force 
        int n = gas.size() ;
        for(int st =0 ;st<n ;st++){
            int curr = gas[st]; ;
                curr-= cost[st] ;
                if(curr<0) continue;
                bool ok = true ;
            for(int j=st+1 ; j%n != st ;j++){
                curr += gas[j%n] ;
                curr-= cost[j%n] ;
                if(curr<0) {
                    ok = false ; break ;
                }
            }
            if(ok) return st ;
        }
        return -1 ;
    }
};
