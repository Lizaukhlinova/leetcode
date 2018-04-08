/*
3. Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        unordered_map <char, int> dict;
        int result = 1;
        int cur = 1;
        dict[s[0]] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (dict.find(s[i]) != dict.end() && dict[s[i]] + cur >= i) {
                cur = i - dict[s[i]];
            } else {
                cur++;
            }

            dict[s[i]] = i;
            result = max(result, cur);
        } 

        return result;
    }
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("bbbbbb") << endl;
	return 0;
}