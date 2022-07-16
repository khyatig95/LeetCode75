
/*
Problem : You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

https://leetcode.com/problems/longest-repeating-character-replacement/

Time Complexity : O(N)
Space Complexity : O(M) where M is the number of characters a string can hold
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        //If replacements allowed > size of string => we can make all of them repeating
        if (k >= size) {
            return size;
        }
        vector<int> count(26, 0);
        int max_count = 0; 
        int window_size = 0;
        int r = 0, l = 0;
        for (int r = 0; r < size; r++) {
            count[s[r]-'A']++;
            max_count = max(max_count, count[s[r] - 'A']);
            if (r-l+1-max_count > k) { //If the current window size - max repeptitions > k => we need to move the window
                count[s[l] - 'A']--;
                l++;
            }
            window_size = max(window_size, r-l+1);
        }
 
        return window_size;
    }
};
