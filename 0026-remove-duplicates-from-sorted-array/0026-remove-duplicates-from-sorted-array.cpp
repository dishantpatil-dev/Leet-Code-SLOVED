class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[temp]<nums[i])
            {
                temp++;
                swap(nums[temp],nums[i]);
            }
        }
        return temp+1;
        
    }
};