class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (!isalpha(s[i])) {
                if (!stk.empty() && stk.top().first == '(' && s[i] == ')') {
                    stk.pop();
                } else {
                    stk.emplace(make_pair(s[i], i));
                }
            }
        }
        while (!stk.empty()) {
            auto tp = stk.top(); stk.pop();
            s.erase(s.begin() + tp.second);
        }
        return s;
    }
};