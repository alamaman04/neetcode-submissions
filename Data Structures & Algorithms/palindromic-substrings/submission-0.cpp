class Solution {
public:

    int extend(string &s , int l , int r){
        int n = s.size() ;
        while(l>=0 && r<n && s[l]==s[r]){ 
            l-- ,r++ ;
        }
        return l;
    }
    int countSubstrings(string s) {
        int n= s.size() ;
        int cnt = 0 ;
        for(int i=0 ;i<n-1;i++){
            cnt+= i-extend(s,i,i) ;
            cnt+=  i-extend(s,i,i+1) ;
        }
        return cnt+1 ;
    }
};
