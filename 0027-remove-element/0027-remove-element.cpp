class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int current=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                swap(nums[i],nums[current]);
                current++;
            }
        }
        return current;
       
    }
};