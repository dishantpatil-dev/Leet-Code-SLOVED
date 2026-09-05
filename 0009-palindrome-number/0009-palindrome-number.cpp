class Solution {
public:
    bool isPalindrome(int x) 
    {
        int rem,n=x,rev=0;
        if (x<0||x%10 == 0 && x!=0)
        {return false;}
        while(n>rev)
        {
	        rem = n % 10;
	        n=n/10;
            rev=rev*10+rem;
        }
        return n == rev||n== rev/10;
    }
};