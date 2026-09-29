class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        
        int max_balance = (m + n) / 2;
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        
        // Initialize start
        if (grid[0][0] == ')') return false;
        dp[0][0].insert(1);
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c].empty()) continue;
                
                // Try moving down
                if (r + 1 < m) {
                    char next_char = grid[r + 1][c];
                    for (int bal : dp[r][c]) {
                        int next_bal = bal + (next_char == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_balance) {
                            dp[r + 1][c].insert(next_bal);
                        }
                    }
                }
                
                // Try moving right
                if (c + 1 < n) {
                    char next_char = grid[r][c + 1];
                    for (int bal : dp[r][c]) {
                        int next_bal = bal + (next_char == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_balance) {
                            dp[r][c + 1].insert(next_bal);
                        }
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1].count(0) > 0;
    }
};