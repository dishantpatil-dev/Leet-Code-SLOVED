class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m;
        for(int i=0;i<n;i++)
        {
            int temp=nums1[x];
            nums1[x]=nums2[i];
            nums2[i]=temp;
            x++;
        }
        for(int i=0;i<m+n-1;i++)
        {
            for(int j=0;j<m+n-1-i;j++)
            {
                if(nums1[j]>nums1[j+1])
                {int temp=nums1[j+1];
                 nums1[j+1]=nums1[j];
                 nums1[j]=temp ;
                }
                
            }
        }
        for(int i:nums1)
        {cout<<i;}
        
    }
};