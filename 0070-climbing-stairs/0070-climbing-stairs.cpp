class Solution {
public:
    int climbStairs(int n) {
        long long fibo=1,st=1;
        for(int i = 0; i < n; i++) 
        {
            long long next = fibo + st;
            fibo = st;
            st = next;
    }
    return fibo;
        
    }
};