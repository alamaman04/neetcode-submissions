class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> need ,window ;
        for(char c : t) need[c]++ ;

        int l = 0 ;
        int m = t.size() ;

        int cnt = 0 ;
        int minlen = 100000 ;
        int start = -1 ;
        // if(cnt ==m) then all the char in t is in window 
        for(int r =0 ;r< s.size() ;r++) {
            window[s[r]]++ ;
            if(window[s[r]]<= need[s[r]]) cnt++ ;
            // shrink the window while cnt ==m
            while(l<r && window[s[l]]>need[s[l]]){
                window[s[l]]--;
                l++ ;
            }
            if(cnt ==m) {
                if(minlen > r-l+1){
                    minlen = r-l+1 ;
                    start = l ;
                }
            }

        }
        if(start == -1 ) return "";
        return s.substr(start,minlen) ;
    }
};
