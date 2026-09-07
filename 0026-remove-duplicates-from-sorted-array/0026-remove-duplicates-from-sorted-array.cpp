class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=0,k=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[n])
            {
                k++;
                n++;
                nums[n]=nums[i];
            }
        }    
        return k;    
    }
};