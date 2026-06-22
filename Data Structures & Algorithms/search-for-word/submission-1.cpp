class Solution {
public:

    bool rec(int r , int c , int i ,string &word ,vector<vector<char>>& board){
        // base case 
        if(i== word.size()-1) return board[r][c]==word[i] ;
        if(board[r][c]!=word[i]) return false; 
        
        int dx[] = {1,-1,0,0} ;
        int dy[]= {0,0,-1,1} ;

        char temp = board[r][c] ;
        board[r][c] = '#' ;
        for(int k=0 ;k<4 ;k++){
            int nr = r+dx[k] ;
            int nc = c+dy[k];
            if(nr>=board.size() || nr<0 || nc<0 || nc>=board[0].size()|| board[nr][nc]=='#') continue;
            if(rec(nr,nc,i+1,word,board)) return true;
        }
        board[r][c] = temp ;
        return false ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size() ;
        int n = board[0].size() ;
        char st = word[0] ;
        for(int i=0 ;i<m;i++){
            for(int j=0 ;j<n ;j++){
                if(board[i][j]== word[0]) if(rec(i,j,0,word,board)) return true;
            }
        }
        return false ;

    }
};
