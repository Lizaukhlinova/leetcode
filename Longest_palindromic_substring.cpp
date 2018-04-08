/*
5. Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Input: "babad"

Output: "bab"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void tryPalindrom(string s, string & result, int j, int k) {
        while (j < s.size() && k >= 0 && s[j] == s[k]) {
            j++;
            k--;
        }
        if (j - k - 1 > result.size()) {
            result = s.substr(k + 1, j - k - 1);
        }
    }

    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s.substr(0, 1);
        string result = (s[0] == s[1]) ? s.substr(0, 2) : s.substr(0, 1);
        for (int i = 2; i < s.size(); i++) {
            tryPalindrom(s, result, i, i - 2);
            tryPalindrom(s, result, i, i - 1);
        }
        return result;
    }
};

int main() {
	Solution s;
	cout << s.longestPalindrome("babad") << endl;
	return 0;
}