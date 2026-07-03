
class Node{
public:
    Node* links[26]= {nullptr} ;
    bool flag = false ;

    bool contain(char ch){
        return links[ch-'a'] != nullptr ;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'] ;
    }

    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag ;
    }
};

class WordDictionary {
private:
    Node* root; 
public:
    WordDictionary() {
        root = new Node() ;
    }
    
    void addWord(string word) {
        Node* node = root ;
        for(auto ch : word){
            if(!node->contain(ch)){
                node->put(ch,new Node()) ;
            }
            node = node->get(ch) ;
        }
        node->setEnd() ;
    }

    bool dfs(int j ,Node* root,string& word){
        Node* node = root ;

        for(int i=j ;i<word.size();i++){
            char c = word[i] ;
            if(c=='.'){
                for(Node* child : node->links){
                    if(child != nullptr && dfs(i+1,child,word)) return true;
                }
                return false;
            }else{
                if(node->links[c-'a'] == nullptr) return false;
                node = node->get(c) ;
            }
        }
        return node->flag ;
    }
    
    bool search(string word) {
        return dfs(0,root,word) ;
    }
};
