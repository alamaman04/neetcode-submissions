class Solution {
public:
    struct DSU{
    public:
        int n ;
        vector<int>par ;
        vector<int>sz ;

        DSU(int n){
            par.resize(n+1) ;
            iota(par.begin() ,par.end() ,0) ;
            sz.assign(n+1,1) ;
        }

        int find(int a ){
            if(par[a]==a) return a ;
            return par[a]= find(par[a]) ;
        }

        bool unite(int a , int b){
            a= find(a), b= find(b) ;
            if(a==b) return false ;
            if(sz[a]<sz[b]) swap(a,b) ;
            sz[a]+= sz[b] ;
            par[b] = a ;
            return true;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        DSU ds(n) ;
        for(int i=0 ;i<n ;i++){
            int a = edges[i][0] ;
            int b = edges[i][1] ;
            if(!ds.unite(a,b)) return {a,b};
        }
        return {} ;
    }
};
