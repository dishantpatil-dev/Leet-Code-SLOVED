class Solution {
public:
    int reverse(int x) {
        int rem,rev=0,x2=x;
           while(x2!=0)
           {
                rem=x2%10;
                x2=x2/10;
                if(rev > INT_MAX / 10)
                {return 0;}

                if (rev < INT_MIN / 10 || 
                (rev == INT_MIN / 10 && rem < -8))
                return 0;
                rev=rev*10+rem;

           } 
           return rev; 
    }
};