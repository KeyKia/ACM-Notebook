string s,t;
int dp[MAX_N][MAX_N];

void LCS() {
    for(int i = 0 ; i < MAX_N ; i++)
        for(int j = 0 ; j < MAX_N ; j++)
            dp[i][j] = 0;
    for(int i = 1 ; i <= s.size() ; i++) {
        for(int j = 1 ; j <= t.size() ; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
