class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;

    bool dfs(int u ){
        vis[u]= 1 ;
        for(auto v : g[u]){
            if(vis[v]==1) return false ;
            if(vis[v]==0){
                if(!dfs(v)) return false ;
            }
        }
        vis[u] = 2 ;
        return true; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build a graph and run
        // if cycle - false ;
        g.resize(numCourses) ;
        vis.assign(numCourses,0) ;
        for(int i=0 ;i<prerequisites.size() ;i++){
            int u = prerequisites[i][0] ;
             int v = prerequisites[i][1] ;
             g[v].push_back(u) ;
        }
        
        bool ans = true ;
        for(int i=0 ;i<numCourses;i++){
           if(vis[i]==0){
               ans &= dfs(i) ;
           }
        }
        return ans;

    }
};
