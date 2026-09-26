class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
      unordered_map<string_view, const string*> k_map;
        k_map.reserve(knowledge.size());
        for (const auto& pair : knowledge) {
            k_map[pair[0]] = &pair[1];
        }
        string res;
        res.reserve(s.length());
        size_t start = 0;
        size_t pos = 0;
        while ((pos = s.find('(', start)) != string::npos) {
            res.append(s, start, pos - start);
            size_t close_pos = s.find(')', pos + 1);
            string_view key(&s[pos + 1], close_pos - pos - 1);
            auto it = k_map.find(key);
            if (it != k_map.end()) {
                res.append(*it->second);
            } else {
                res.push_back('?');
            }
            start = close_pos + 1;
        }
        if (start < s.length()) {
            res.append(s, start, s.length() - start);
        }

        return res;
        
    }
};