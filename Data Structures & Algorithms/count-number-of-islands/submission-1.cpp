class Solution {
public:
    // const int N = 10000+5 ;
    // vector<int>size,par ;
    // int cc ;

    // void DSU(int n){
    //     par.resize(n);
    //     size.assign(n,1) ;
    //     iota(par.begin(),par.end() ,0) ;
    //     cc = 0;
    // }


    // // code for union find 
    // int find(int u) {
    //     if(par[u]==u)return u ;
    //     return par[u] = find(par[u]) ;
    // }

    // void unite(int u ,int v) {
    //     u = find(u) ;
    //     v = find(v) ;
    //     if(u!=v) {
    //         if(size[u]<size[v]) swap(u,v) ;
    //         par[v] = u ;
    //         size[u]+= size[v];
    //         cc-- ;
    //     }
    // }
    
    vector<vector<int>>vis ;


    bool valid(int i, int j ,int m ,int n){
        if(i>=0 && i<m && j>=0 && j<n) return true ;
        return false ;
    }
    void dfs(int i , int j,vector<vector<char>> & grid,int &m ,int &n){
        
        vis[i][j] = 1 ;
        int dx[] = {1,-1,0,0} ;
        int dy[] = {0,0,1,-1} ;

        for(int d=0 ;d<4 ;d++){
            int ni = i+dx[d] ;
            int nj = j+dy[d] ;
            if(valid(ni,nj,m,n) && !vis[ni][nj] && grid[ni][nj]=='1') dfs(ni,nj,grid,m,n) ;
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        // make the graph 
        int m = grid.size() ;
        int n = grid[0].size() ;

        //DSU(m*n) ;
        vis.assign(m,vector<int>(n,0)) ;
        int cc = 0 ;
        for(int i=0;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(i,j,grid,m,n) ;
                    cc++ ;
                }
            }
        }
        
        return cc ;

    }
};
