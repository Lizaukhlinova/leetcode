/*
394.
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated 
exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those 
repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
	vector <string> digits;
	vector <string> buffer;
	string result = "";
public:
    string decodeString(string s) {
        for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				buffer.push_back("");
			} else if (isalpha(s[i])) {
				if (buffer.empty()) 
					buffer.push_back("");
				buffer[buffer.size() - 1] += s[i];
			} else if (isdigit(s[i])) {
				if (i > 0 && isdigit(s[i - 1]))
					digits[digits.size() - 1] += s[i];
				else {
					string temp = "";
					temp += s[i];
					digits.push_back(temp);
				}
			} else if (s[i] == ']') {
				int count = stoi(digits.back());
				digits.pop_back();
				string pattern = "";
				for (int j = 0; j < count; j++) {
					pattern += buffer[buffer.size() - 1];
				}
				buffer.pop_back();
				if (!buffer.empty()) {
					buffer[buffer.size() - 1] += pattern;
				} else {
					result += pattern;
				}
			} 
		}

		if (!buffer.empty()) 
			result += buffer[buffer.size() - 1];

		return result;
    }
};

int main() {
	string s = "100[a]";
	Solution r;

	cout << r.decodeString(s) << endl;

	return 0;
}