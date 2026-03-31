class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int required = t.size();   // total characters needed
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            // include current character
            if (need[s[right]] > 0) {
                required--;
            }
            need[s[right]]--;
            right++;

            // when window is valid, try to shrink
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // remove left character
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    required++;  // window no longer valid
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
