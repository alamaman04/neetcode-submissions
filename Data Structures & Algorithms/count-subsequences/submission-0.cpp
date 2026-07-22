class Solution {
public:
    
    int rec(int i , int j, string& s , string &t,vector<vector<int>>& memo){
        if(i==s.size()){
            if(j==t.size()) return 1 ;
            return 0 ;
        }
        if(memo[i][j]!= -1) return memo[i][j] ;

        int distinct = 0 ;
        if(s[i]==t[j]) distinct+= rec(i+1,j+1,s,t,memo) ;
        distinct+= rec(i+1,j,s,t,memo) ;
        return memo[i][j] = distinct ;
    }
    int numDistinct(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;
        if(n<m) return 0 ;
        vector<vector<int>>memo(n,vector<int>(n,-1)) ;
        return rec(0,0,s,t,memo) ;


    }
};
