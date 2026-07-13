class Solution {
public:

    vector<int>memo ;
    bool rec(int idx ,string& s , vector<string>&wordDict){
        if(idx == s.size())return true ;
        if(memo[idx] != -1) return memo[idx];
        
        bool ans = false ;
        for(auto word : wordDict){
            // check wether word match with the rem substring starting at idx 
            int i = idx , j = 0 ;
            while(i<s.size() && j< word.size() && s[i] == word[j]) i++ , j++ ;
            if(j==word.size()){
                ans |= rec(i,s,wordDict) ;
            }
        }
        return memo[idx]= ans ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       memo.assign((int)s.size(),-1) ;
        return rec(0,s,wordDict) ;
    }
};
