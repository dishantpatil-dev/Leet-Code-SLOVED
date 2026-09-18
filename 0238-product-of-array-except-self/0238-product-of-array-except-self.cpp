class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> ans(nums.size(), 1);
     int start=0,end=nums.size()-1;
     int preproduct=1,sufproduct=1;
     for(int i=1;i<nums.size();i++)
     {
        if(start<i)
        {
            preproduct*=nums[start];
            ans[i]*=preproduct;
            start++;
        }
        if(end>=0)
        {
            sufproduct*=nums[end];
            ans[nums.size()-i-1]*=sufproduct;
            end--;
        }

     }   
     return ans;
        
    }
};