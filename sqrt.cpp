/*
69. Implement int sqrt(int x).
Compute and return the square root of x.
x is guaranteed to be a non-negative integer.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r * r > x) {
        	r = 0.5 * (r + x / r);
        }
        return r;
    }
};

int main() {
	Solution s;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(18) << endl;
	return 0;
}