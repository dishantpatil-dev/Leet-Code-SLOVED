class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int k=0;k<nums.size()-2;k++)
        {
            if(k > 0 && nums[k] == nums[k-1])
            continue;
            int i = k + 1,j = nums.size() - 1;
            while(i<j)
            {
                int sum=nums[k]+nums[i];
                if(sum+nums[j]>0)
            {
                j--;
                while(i<j&& nums[j]==nums[j+1])
                {
                    j--;
                }
            }
            else if(sum+nums[j]<0)
            {
                i++;
                while( i < j && nums[i]==nums[i-1])
                {
                    i++;
                }
            }
            else
            {
                ans.push_back({nums[k], nums[i], nums[j]});
                i++;
                while( i < j && nums[i]==nums[i-1])
                {
                    i++;
              }
            }
        }
    }

    return ans;
}

};