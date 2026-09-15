class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> ans(arr.size());
        ans[arr.size()-1]=-1;
        int big=arr[arr.size()-1];
        for(int i=arr.size()-1;i>=1;i--)
        {
            if(big<arr[i])
            {
                big=arr[i];
            }
            ans[i-1]=big;

        }
        return ans;
        
    }
};