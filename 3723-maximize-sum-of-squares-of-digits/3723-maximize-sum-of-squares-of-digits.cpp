class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the maximum possible sum with 'num' digits is less than 'sum', it's impossible
        if ((long long)num * 9 < sum) {
            return "";
        }
        
        std::string result = "";
        
        // Greedily place '9's from left to right
        for (int i = 0; i < num; ++i) {
            int digit = std::min(9, sum);
            result += std::to_string(digit);
            sum -= digit;
        }
        
        return result;
    }
};