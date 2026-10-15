class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctElements;
            for (int j = i; j < n; j++) {
                distinctElements.insert(nums[j]);
                int count = distinctElements.size();
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};