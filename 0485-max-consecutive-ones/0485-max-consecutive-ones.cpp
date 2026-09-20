class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int freq=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                freq++;
                ans=max(freq,ans);
            }
            else{
                freq=0;
            }

            
        }
        return ans;

        
    }
};