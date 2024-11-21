/*
# Intuition
It represents a classical Binary search problem as the numbers are sorted

# Approach
I used three variables for this approach:

-->first to store the starting index (initially 0),
-->last to store the ending index (nums.size() - 1),
-->mid to store the index that divides the array into two halves.

Since the numbers are sorted in ascending order, we use a binary search approach:

If the number at the mid index is smaller than the target, we shift our search to the right half by updating first to mid + 1.

If the number at the mid index is larger than the target, we shift our search to the left half by updating last to mid - 1.

If we find the number at mid to be equal to the target, we return mid as the index.

If the target number is not found after the search concludes, we return the index where it would be inserted to maintain the array's sorted order.

This approach ensures an O(log n) time complexity due to the halving of the search range in each step.

# Complexity
- Time complexity: O(Log(N))

- Space complexity: O(1)
*/


//Code
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int first = 0, last = nums.size() - 1;
        int mid;
        while (first <= last) {
            mid = first + (last - first) / 2; 
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                first = mid + 1; // Move to the right half
            } else {
                last = mid - 1; // Move to the left half
            }
        }
        return first;
    }
};