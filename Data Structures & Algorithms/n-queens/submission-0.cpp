class Solution {
public:

    vector<vector<string>>ans ;

    bool valid(int r ,int c ,int &n ,vector<string>&state){
        // check the same row 
        for(int i=0 ;i<c ;i++){
            if(state[r][i]=='Q') return false;
        }
        // check left upper diognal 
        for(int i=c-1 ;i>=0 ;i--){
            int row = r-(c-i) ;
            if(row >= 0 && state[row][i]=='Q') return false; 
        }
        // check bottom left diaognal
        for(int i=c-1 ;i>=0 ;i--){
            int row = r+(c-i) ;
            if(row < n && state[row][i]=='Q') return false ;
        }
        return true; 
    }


    void place(int c ,int &n,vector<string>& state){
        // base case 
        if(c==n) {
            ans.push_back(state) ;
            return ;
        }
        for(int i=0 ;i<n;i++){
            if(!valid(i,c,n,state)) continue;
            state[i][c] ='Q' ;
            place(c+1,n,state) ;
            state[i][c] = '.' ;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>state ;
        for(int i=0 ;i<n;i++){
            string s = "" ;
            for(int j=0 ;j<n;j++) {
                s+= '.' ;
            }
            state.push_back(s) ;
        }
        place(0,n,state) ;
        return ans;
    }
};
