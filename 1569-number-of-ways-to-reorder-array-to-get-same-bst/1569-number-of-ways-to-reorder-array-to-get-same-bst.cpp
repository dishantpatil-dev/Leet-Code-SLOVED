class Solution {
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    // Helper to compute combination C(n, k) using Pascal's triangle
    long long combination(int n, int k) {
        if (k > n || k < 0) return 0;
        if (k == 0 || k == n) return 1;
        if (table[n][k] != 0) return table[n][k];
        return table[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % MOD;
    }

    long long dfs(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        std::vector<int> left, right;
        int root = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(left) % MOD;
        long long rightWays = dfs(right) % MOD;

        // Combinations of choosing positions for left subtree elements out of (left.size() + right.size()) spots
        long long ways = combination(left.size() + right.size(), left.size());
        
        return (((ways * leftWays) % MOD) * rightWays) % MOD;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        table = std::vector<std::vector<long long>>(n + 1, std::vector<long long>(n + 1, 0));
        
        // Subtract 1 because the problem asks for ways to *reorder* nums 
        // (excluding the original arrangement itself).
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};