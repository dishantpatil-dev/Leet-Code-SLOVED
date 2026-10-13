class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        
        long long score = 0;
        int mid = n / 2;
        
        // Subtract squares of the smaller half
        for (int i = 0; i < mid; ++i) {
            score -= (long long)nums[i] * nums[i];
        }
        
        // Add squares of the larger half
        for (int i = mid; i < n; ++i) {
            score += (long long)nums[i] * nums[i];
        }
        
        return score;
    }
};