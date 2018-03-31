/*
136. Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};

int main() {
	Solution s;
    vector <int> v = {1, 2, 3, 2, 1, 3, 5, 6, 6};
	cout << s.singleNumber(v) << endl;
	return 0;
}