class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Step 1: Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        
        // Step 2: Find all indices matching the target
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};