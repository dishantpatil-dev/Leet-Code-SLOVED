class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,max_subarray=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            max_subarray=max(sum,max_subarray);
            if(sum<0)
            {
            sum=0;
            }
        }
        return max_subarray;

        
    }
};