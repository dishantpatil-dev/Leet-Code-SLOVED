class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(nums[i]!=0)
            {
                int rem=nums[i]%10;
                ans.push_back(rem);
                nums[i]/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};