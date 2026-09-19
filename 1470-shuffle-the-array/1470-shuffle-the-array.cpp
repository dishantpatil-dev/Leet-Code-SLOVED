class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int k = 0; k < n; k++) {
            ans[2 * k] = nums[k];
            ans[2 * k + 1] = nums[k + n];
        }

        return ans;
    }
};