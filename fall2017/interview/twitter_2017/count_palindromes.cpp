
typedef vector<int> vi;
typedef vector<vi> vvi;
int countPalindromes(string s) {

    vvi dp(5e3, vi(5e3, 0));
    vvi pal(5e3, vi(5e3, 0));

    for(int i = 0; i < s.size(); i++) {
        pal[i][i] = 1;
        dp[i][i] = 1;
    }

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            pal[i][i+1] = 1;
            dp[i][i+1] = 3;
        } else {
            dp[i][i+1] = 2;
        }
    }

    for(int n=2; n < s.size(); n++) {
        for(int i = 0; i < s.size()-n; i++) {
            int j = n + i;
            if(s[i] == s[j] && pal[i+1][j-1] == 1) {
                pal[i][j] = 1;
            }
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + pal[i][j];
        }
    }

    return dp[0][s.size()-1];

}
