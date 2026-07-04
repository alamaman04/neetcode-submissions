class Solution {
public:


    class Node{
    public:
        Node* links[26] = {nullptr} ;
        bool flag = false ;
        int index = -1 ;
    };
    
    class Trie{
    public:
        Node* root ;
        Trie(){
            root= new Node() ;
        }

        void insert(string word, int idx){
            Node* curr = root ;
            for(auto ch : word){
                if(curr->links[ch-'a'] == nullptr) {
                    curr->links[ch-'a'] = new Node() ;
                }
                curr = curr->links[ch-'a'] ;
            }
            curr->flag = true ;
            curr->index = idx ;
        }

        int search(string word ){
            Node* curr= root ;
            for(auto ch : word){
                if(curr->links[ch-'a'] == nullptr) return -1 ;
                curr = curr->links[ch-'a'] ;
            }
            if(curr->flag){
                return curr->index ;
            }
            return -1 ;
        }
    };

    vector<string>res ;

    bool valid(int r , int c ,int m , int n){
        if(r>=0 && r<m && c>=0 && c<n) return true ;
        return false;
    }

    void dfs(int r , int c , Node* node , vector<vector<char>>& board,vector<string>& words){
        // base case 
        char ch = board[r][c] ;
        if(node->links[ch-'a']== nullptr ) return ;
        node = node->links[ch-'a'];
        if(node->flag && node->index != -1){
            res.push_back(words[node->index]);
            node->index = -1 ;
            node->flag =false ;
        }
        int m = board.size() , n =board[0].size() ;
        int dx[] = {0,0,1,-1} ;
        int dy[] = {1,-1,0,0} ;
        board[r][c] = '#' ;
        for(int id =0 ;id<4 ;id++){
            int nr = r + dx[id] ;
            int nc = c + dy[id] ;
            if(valid(nr,nc,m,n) && board[nr][nc]!='#') dfs(nr,nc,node,board,words);
        }
        board[r][c] = ch ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // build the trie
        Trie* trie = new Trie() ;
        for(int i=0 ;i<words.size() ;i++){
            trie->insert(words[i],i) ;
        }
        for(int i=0 ;i<board.size() ;i++){
            for(int j=0 ;j<board[i].size(); j++){
                dfs(i,j,trie->root,board,words) ;
            }
        }
        return res ;

    }
};
