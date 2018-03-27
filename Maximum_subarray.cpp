/*
53. Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector <int> d(nums.size(), 0);
        d[0] = nums[0];
        int res = d[0];
        for (int i = 1; i < nums.size(); i++) {
            d[i] = nums[i] + (d[i - 1] > 0 ? d[i - 1] : 0);
            res = max(res, d[i]);
        }
        return res;
    }
};

int main() {
    vector <int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution s;
	cout << s.maxSubArray(v) << endl;
	return 0;
}