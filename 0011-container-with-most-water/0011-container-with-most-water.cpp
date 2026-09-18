class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxwater=INT_MIN,water,H,B;
        while(i<j)
        {
            H=min(height[i],height[j]);
            B=j-i;
            water=H*B;
            maxwater=max(water,maxwater);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            


        }
        return maxwater;
        
    }
};