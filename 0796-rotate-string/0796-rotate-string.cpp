class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
        {
            return true;
        }
        for(int i=0;i<s.size()-1;i++)
        {
            reverse(s.begin(),s.end()-1);
            reverse(s.begin(),s.end());
            if(s==goal)
            {
                return true;
            }
           
        }
         return false;
    } 

};