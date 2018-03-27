/*
7. Given a 32-bit signed integer, reverse digits of an integer.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};

int main() {
    Solution s;
	cout << s.reverse(-123) << endl;
	return 0;
}