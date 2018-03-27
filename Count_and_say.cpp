/*
38. The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
Given an integer n, generate the nth term of the count-and-say sequence.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";
        string prev = "11";
        string result = prev;
        for (int i = 2; i < n; i++) {
            result = "";
            int count = 1;
            char c = prev[0];
            for (int k = 1; k < prev.size(); k++) {
                if (prev[k] == prev[k - 1]) 
                    count++;
                else {
                    result += string(1, char(count + '0')) + string(1, c);
                    c = prev[k];
                    count = 1;
                }
            }
            result += to_string(count) + c;
            prev = result;
        }
        return prev;
    }
};

int main() {
	Solution s;
	cout << s.countAndSay(5) << endl;
	return 0;
}