class Solution {
public:
    vector<string>ans ;


    void comb(int idx ,int &n, string &curr , string & digits,vector<string>&lookup){
        // base case 
        if(idx==n) {
            ans.push_back(curr);return ;
        }
        int num = digits[idx]-'0' ;
        for(int i=0 ;i<lookup[num].size() ;i++){
            curr+= lookup[num][i];
            comb(idx+1,n,curr,digits,lookup);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        ans.clear() ;
        int n = digits.size() ;
        if(n==0) return ans; 
        vector<string>lookup(10) ;
        lookup[2] = "abc" ;
        lookup[3] = "def" ;
        lookup[4] = "ghi" ;
        lookup[5] = "jkl" ;
        lookup[6] = "mno" ;
        lookup[7] = "pqrs" ;
        lookup[8] = "tuv" ;
        lookup[9] = "wxyz" ;
        string curr = "" ;
        comb(0,n,curr,digits,lookup) ;
        return ans ;

    }
};
