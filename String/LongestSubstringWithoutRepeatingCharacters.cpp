/*
Problem : Given a string s, find the length of the longest substring without repeating characters.

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        if (sz == 0)
            return 0;
        if (sz == 1)
            return 1;
        int head = 0, length = 1;
        unordered_map<char, int> umap;
        for (int i=0; i<sz; i++) {
            if (umap.find(s[i]) != umap.end()) { //Found s[i] => move start of substring to last (not the current) occurence of s[i]+1 
                head = max(head, umap[s[i]]+1);
            }
            umap[s[i]] = i; //Store only last occurence in case of duplicating characters
            length = max(i-head+1, length);
        }
        return length;
    }
};
