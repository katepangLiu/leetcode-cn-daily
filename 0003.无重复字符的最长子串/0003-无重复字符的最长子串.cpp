class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLen = s.length();
        int maxLen = 0;
        map<char, int> freq;
        int left = 0;
        int right = 0;

        while( right < sLen ) {
            while( freq[s[right]] != 0 ) {
                freq[s[left]]--;
                left++;
            }
            freq[s[right]]++;
            right++;
            maxLen = max(maxLen, right-left);
        }

        return maxLen;
    }
};