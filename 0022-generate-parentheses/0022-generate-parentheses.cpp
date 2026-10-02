class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        function<void(int, int)> backtrack = [&](int open, int close) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }

            if (open < n) {
                s += '(';
                backtrack(open + 1, close);
                s.pop_back();
            }

            if (close < open) {
                s += ')';
                backtrack(open, close + 1);
                s.pop_back();
            }
        };

        backtrack(0, 0);
        return ans;
    }
};