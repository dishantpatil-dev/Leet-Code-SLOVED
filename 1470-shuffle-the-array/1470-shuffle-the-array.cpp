class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int i=0,j=n;
        for( int k=0;k<2*n;k+=2)
        {
            ans[k]=nums[i];
            ans[k+1]=nums[j];
            i++;
            j++;
        }
        return ans;
        
    }
};