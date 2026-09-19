class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        int n=nums.size()-1,j=0;
        for(int i=0;i<ans.size();i++)
        {
            ans[i]=nums[j];
            j++;
            if(i==n)
            {
                j=0;
            }
        }

            return ans;

        
    }
};