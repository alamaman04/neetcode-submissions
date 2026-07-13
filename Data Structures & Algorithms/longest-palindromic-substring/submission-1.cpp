class Solution {
public:

    string extend(string &s , int l , int r){
        int n = s.size() ;
        while(l>=0 && r<n && s[l]==s[r]){ 
            l-- ,r++ ;
        }
        return s.substr(l+1,r-l-1) ;
    }
    string longestPalindrome(string s) {
        int n= s.size() ;
        string res = "" ;
        for(int i=0 ;i<n;i++){
            string odd = extend(s,i,i) ;
            string even = extend(s,i,i+1) ;
            if(odd.size()>res.size()){
                res = odd ;
            }
            if(even.size() > res.size()){
                res = even ;
            }
        }
        return res ;
    }
};
