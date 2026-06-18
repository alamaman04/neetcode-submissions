class Solution {
public:
    vector<vector<int>>vis ;
    
    void dfs(int r ,int c ,vector<vector<int>>& heights,vector<vector<bool>>& hash){
        int m = heights.size() ;
        int n = heights[0].size() ;
        hash[r][c] = true ;
        vis[r][c] = true ;
        int dx[] = {1,-1,0,0} ;
        int dy[] = {0,0,-1,1} ;

        for(int i=0 ;i<4 ;i++){
            int nr = r+dx[i] ;
            int nc = c+dy[i] ;
            if(nr>=m||nr<0 ||nc>=n||nc<0|| vis[nr][nc]|| heights[nr][nc]<heights[r][c] )continue;
            dfs(nr,nc,heights,hash) ;
        }



    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size() ;
        int n = heights[0].size();
        vis.assign(m,vector<int>(n,0)) ;
        vector<vector<bool>>pacific,atlantic  ;
         pacific.assign(m,vector<bool>(n,false)) ;
         atlantic.assign(m,vector<bool>(n,false)) ;

         // call pacific cells 
         // upper row 
         for(int i=0 ;i<n;i++){
            if(!vis[0][i]) dfs(0,i,heights,pacific) ;
         }
         // left col
         for(int i=1 ;i<m ;i++){
            if(!vis[i][0]) dfs(i,0,heights,pacific) ;
         }

          vis.assign(m,vector<int>(n,0)) ;

          // call atlantic side 
          for(int i=0 ;i<m;i++){
            if(!vis[i][n-1]) dfs(i,n-1,heights,atlantic);
          }
          for(int i=0 ;i<n;i++){
            if(!vis[m-1][i]) dfs(m-1,i,heights,atlantic) ;
          }

          vector<vector<int>>ans;
          for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j}) ;
            }
          }
          return ans ;



    }
};
