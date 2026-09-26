class Solution {
public:
    int lengthOfLastWord(string s) {
        int freq=0,ans=INT_MIN;
        if(s.size()==1)
        {return 1;}
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=32)
            {
                freq++;
               
            }
            else if(freq>0)
            {return freq;}
        }
        return freq;
        
    }
};