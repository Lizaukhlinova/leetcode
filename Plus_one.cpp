/*
66. Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) {
        	r = 0.5 * (r + x / r)
        }
        return r;
    }
};

int main() {
	Solution s;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(8) << endl;
	return 0;
}