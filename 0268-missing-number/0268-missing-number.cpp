class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,arr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+i+1;
            arr_sum+=nums[i];
        }
        return sum-arr_sum;
        
    }
};