class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // start from anyw
        // brutre force 
        int n = gas.size() ;
        // for(int st =0 ;st<n ;st++){
        //     int curr = gas[st]; ;
        //         curr-= cost[st] ;
        //         if(curr<0) continue;
        //         bool ok = true ;
        //     for(int j=st+1 ; j%n != st ;j++){
        //         curr += gas[j%n] ;
        //         curr-= cost[j%n] ;
        //         if(curr<0) {
        //             ok = false ; break ;
        //         }
        //     }
        //     if(ok) return st ;
        // }
        // return -1 ;
        if(accumulate(gas.begin() ,gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1 ;
        int tank = 0 ;
        int res = 0 ;
        for(int i=0 ;i<n;i++){
            tank += gas[i] - cost[i] ;
            if(tank<0) {
                res = i+1 ;
                tank = 0 ;
            }
        }
        return res ;

    }
};
