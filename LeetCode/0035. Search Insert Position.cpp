/*
0035. Search Insert Position

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

*/

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        
        // 特殊情形
        if (len == 0)
            return 0;
        if (target > nums[len - 1])
            return len;

        int left = 0, right = len;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid]) {
                right = mid;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        return left;
    }
};