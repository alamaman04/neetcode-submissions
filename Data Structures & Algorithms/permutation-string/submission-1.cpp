class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size() ;
        int n = s2.size() ;
        if(m>n) return false ;

        // with using extra space 
        vector<int>need(26) , window(26) ;
        for(char c : s1) need[c-'a']++ ;
       
        for(int i=0 ;i<m ;i++){
           window[s2[i]-'a']++ ;
        }
       if(window == need) return true ;

       for(int r = m ;r< n ; r++){
          window[s2[r]-'a']++ ;
          window[s2[r-m]-'a'] -- ;
          if(need == window) return true ;
       }
        return false ;
    }
};
