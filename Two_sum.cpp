/*
1. Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map <int, int> comp;
    	vector <int> result;
    	for (int i = 0; i < nums.size(); i++) {
    		if (comp.find(target - nums[i]) != comp.end()) {
    			result.push_back(comp[target - nums[i]]);
    			result.push_back(i);
    			break;
    		} else {
    			comp.insert(make_pair(nums[i], i));
    		}
    	}
    	return result;
    }
};

int main() {
	vector <int> v = {0, 3, 12, 2, 7, 11, 15};
	int target = 9;
	Solution s;
	auto res = s.twoSum(v, target);
	for (auto x : res) {
		cout << x << ' ';
	}

	return 0;
}