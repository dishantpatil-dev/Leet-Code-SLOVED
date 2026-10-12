class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCounts(30, 0);
        
        // Count the frequency of each bit across all numbers
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((x >> i) & 1) {
                    bitCounts[i]++;
                }
            }
        }
        
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        
        // Greedily form the k numbers to maximize their values
        for (int step = 0; step < k; ++step) {
            long long currentVal = 0;
            for (int i = 0; i < 30; ++i) {
                if (bitCounts[i] > 0) {
                    currentVal |= (1 << i);
                    bitCounts[i]--;
                }
            }
            totalSum = (totalSum + (currentVal * currentVal) % MOD) % MOD;
        }
        
        return totalSum;
    }
};