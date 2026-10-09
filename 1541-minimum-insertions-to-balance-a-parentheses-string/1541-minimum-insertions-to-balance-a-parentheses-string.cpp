class Solution {
public:
    int minInsertions(string s) {
        int res = 0, need = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                need += 2;
                if (need % 2 != 0) {
                    res++;
                    need--;
                }
            } else {
                need--;
                if (need < 0) {
                    res++;
                    need += 2;
                }
            }
        }
        return res + need;
    }
};