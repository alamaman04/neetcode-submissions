class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        // build the adj 
        vector<vector<pair<int,int>>> g (n) ;
        for(int i =0 ;i<n;i++){
            int x = points[i][0] , y = points[i][1];
            for(int j=i+1 ;j<n ;j++){
                int nx = points[j][0], ny = points[j][1];
                int wt = abs(nx-x) + abs(ny-y);
                g[i].push_back({j,wt}) ;
                g[j].push_back({i,wt});
            }
        }
        int mincost = 0 ;
        vector<bool>vis(n) ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q ;
        q.push({0,0});

        while(!q.empty()){
            auto p = q.top() ;q.pop() ;
            int wt = p.first;
            int u = p.second ;
            if(vis[u])continue ;
            vis[u]= true ;
            mincost+= wt ;

            for(auto [v,w] : g[u]){
                if(!vis[v]){
                    q.push({w,v}); 
                }
            }
        }

        return mincost ;
    }
};
