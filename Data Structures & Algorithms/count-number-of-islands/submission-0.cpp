class Solution {
public:
    const int N = 10000+5 ;
    vector<int>size,par ;
    int cc ;

    void DSU(int n){
        par.resize(n);
        size.assign(n,1) ;
        iota(par.begin(),par.end() ,0) ;
        cc = 0;
    }


    // code for union find 
    int find(int u) {
        if(par[u]==u)return u ;
        return par[u] = find(par[u]) ;
    }

    void unite(int u ,int v) {
        u = find(u) ;
        v = find(v) ;
        if(u!=v) {
            if(size[u]<size[v]) swap(u,v) ;
            par[v] = u ;
            size[u]+= size[v];
            cc-- ;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // make the graph 
        int m = grid.size() ;
        int n = grid[0].size() ;

        DSU(m*n) ;
        for(int i=0;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(grid[i][j]=='0') continue ;
                cc++ ;
                int u = i*n+j ;
                if(j<n-1 && grid[i][j+1]=='1'){
                    unite(u,u+1);
                }
                if(i<m-1 && grid[i+1][j]=='1'){
                    int v = (i+1)*n+j ;
                   unite(u,v);
                }

            }
        }
        
        return cc ;

    }
};
