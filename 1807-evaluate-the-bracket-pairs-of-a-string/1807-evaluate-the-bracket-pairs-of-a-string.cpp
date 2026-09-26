class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> k_map;
        for (const auto& pair : knowledge) {
            k_map[pair[0]] = pair[1];
        }

        string res = "";
        string key = "";
        bool in_bracket = false;

        // Step 2: Parse string
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                auto it = k_map.find(key);
                if (it != k_map.end()) {
                    res += it->second;
                } else {
                    res += '?';
                }
                key.clear();
            } else {
                if (in_bracket) {
                    key += c;
                } else {
                    res += c;
                }
            }
        }

        return res;
        
    }
};