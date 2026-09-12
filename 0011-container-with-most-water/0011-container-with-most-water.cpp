class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int MAXWATER=0,H,W,water;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            H=min(height[i],height[j]);
            W=j-i;
            water=W*H;
            if(water>MAXWATER)
            {MAXWATER=water;}
            if(height[i]==min(height[i],height[j]))
            {
                i++;
            }
            else
            {
                j--;
            }

        }
        return MAXWATER;
        
    }
};