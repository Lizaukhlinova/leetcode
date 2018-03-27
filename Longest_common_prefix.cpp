/*
14. Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0) return "";
    	string result = strs[0];
    	for (string s : strs) {
    		while (s.find(result) != 0) {
    			result.pop_back();
    			if (result.empty())
    				return "";
    		}
    	}
    	return result;
    }

};

int main() {
	vector<string> strs = {"qwerty", "qwedf", "qwsert"};
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}