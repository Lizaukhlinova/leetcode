/*
326. Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }

    bool recursiveIsPowerOfThree(int n) {
    if (n <= 0) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
    }
};

int main() {
	Solution s;
	cout << s.isPowerOfThree(3) << ' ' << s.isPowerOfThree(5) << ' ' << s.isPowerOfThree(81) << endl;
    cout << s.recursiveIsPowerOfThree(3) << ' ' << s.recursiveIsPowerOfThree(5) << ' ' << s.recursiveIsPowerOfThree(81) << endl;
	return 0;
}