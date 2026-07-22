class Solution {
   public:
    vector<vector<int>> memo;
    bool solve(int i, int j, string& s, string& p) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (memo[i][j] != -1) return memo[i][j];

        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');

        bool ans;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            ans = solve(i, j + 2, s, p) || (firstMatch && solve(i + 1, j, s, p));
        } else {
            ans = solve(i + 1, j + 1, s, p) && firstMatch;
        }
        return memo[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        memo.assign(n + 1, vector<int>(m + 1, -1));
        // return solve(0,0,s,p) ;

        // tabulation
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[n][m] = true;
        for (int i = n ; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if(p[j]=='*') continue;
                bool firstMatch = i<n && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < m && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
