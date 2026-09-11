class Solution {
public:
    int maxArea(vector<int>& height) {
        int MAXWATER=0,water=0;
        int i=0,j=height.size()-1,H,W;
        while(i<j)
        {
            W=j-i;
            H=min(height[i],height[j]);
            water=W*H;
            MAXWATER=max(MAXWATER,water);
            if(height[i]<height[j])
            {i++;}
            else
            {j--;}

        }
        return MAXWATER;
        
    }
};