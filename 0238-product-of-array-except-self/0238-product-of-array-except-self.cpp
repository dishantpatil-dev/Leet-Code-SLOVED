class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> ans(nums.size(), 1);
     int end=nums.size()-1;
     int preproduct=nums[0],sufproduct=nums[end];
     for(int i=1;i<nums.size();i++)
     {
        ans[i]*=preproduct;
        preproduct*=nums[i];
        ans[end-i]*=sufproduct;
        sufproduct*=nums[end-i];
     }
     return ans;
    }
};