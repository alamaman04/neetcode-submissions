class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        long long inf = (1LL<<31) -1 ;
        int m = grid.size() ;
        int n = grid[0].size() ;

        queue<pair<pair<int,int>,int>>q ; // {{i,j},dis} ;
        
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n; j++) {
                if(grid[i][j]==0) q.push({{i,j},0}) ;
            }
        }

        auto isValid = [&](int a , int b){
            if(a>=0 && a<m && b>=0 && b<n) return true ;
            else return false ;
        };

        int dx[] = {1,-1,0,0} ;
        int dy[] = {0,0,-1,1} ;

        while(!q.empty()){
            auto p = q.front() ;q.pop() ;
            int i = p.first.first ;
            int j = p.first.second ;
            int dis = p.second ;
            if(grid[i][j]<dis) continue ;
            grid[i][j] = dis ;

            for(int d =0 ;d<4 ;d++){
                int ni = i+dx[d];
                int nj = j+dy[d];
                if(isValid(ni,nj) && grid[ni][nj]==inf ){
                    q.push({{ni,nj},dis+1}) ;
                }
            }
        }
        return  ;
        
        
    }
};
