class Solution {
public:
    
     static bool closeStrings(const string& word1, const string& word2) {
        // Short circuit different word lengths.
        if (size(word1) != size(word2)) return false;

        return signature(word1) == signature(word2);
    }
     static array<int, 27> signature(const string& word) {
        array<int, 27> ans = {};
        int seen = 0;
        for (char ch : word) {
            ch -= 'a';
            ++ans[ch];
            seen |= 1 << ch;
        }
        sort(begin(ans), end(ans));
        ans[26] = seen;
        return ans;
    }
};