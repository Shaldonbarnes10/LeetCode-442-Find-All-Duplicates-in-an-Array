# LeetCode 442: Find All Duplicates in an Array

## Problem Statement
Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **at most twice**, return an array of all the integers that appear **twice**.

### **Example 1**
**Input:**
```cpp
nums = [4,3,2,7,8,2,3,1]
```
**Output:**
```cpp
[2,3]
```

### **Example 2**
**Input:**
```cpp
nums = [1,1,2]
```
**Output:**
```cpp
[1]
```

### **Example 3**
**Input:**
```cpp
nums = [1]
```
**Output:**
```cpp
[]
```

## Constraints
- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`
- Each element in `nums` appears **once or twice**.

## **Optimal Approach: Index Marking (Negation Technique)**
### **Algorithm**
1. Iterate through the array.
2. For each number `num`, use its absolute value as an index (`abs(num) - 1`).
3. If `nums[index]` is **already negative**, it means `num` is a duplicate → **Add it to the result**.
4. Otherwise, negate `nums[index]` to mark it as visited.
5. Return the list of duplicate elements.

## **C++ Implementation**
```cpp
#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        int index = abs(num) - 1; // Convert value to index
        
        if (nums[index] < 0) { // If already marked negative, it's a duplicate
            result.push_back(abs(num));
        } else {
            nums[index] = -nums[index]; // Mark as visited
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    
    // Output the result
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

## **Time & Space Complexity**
- **Time Complexity:** `O(n)` (Each element is visited at most twice)
- **Space Complexity:** `O(1)` (Modifies the input array in place, excluding output storage)

## **Why This Approach?**
✅ Runs in **O(n) time** (efficient for large inputs).  
✅ Uses **O(1) extra space** (modifies the input array).  
✅ Avoids additional data structures like hash maps or sets.

## **Alternative Approaches**
| Approach | Time Complexity | Space Complexity |
|----------|---------------|-----------------|
| Sorting (Compare Adjacent Elements) | `O(n log n)` | `O(1)` |
| Hash Map (Frequency Count) | `O(n)` | `O(n)` |
| **Index Marking (Negation) [Optimal]** | `O(n)` | `O(1)` |

## **Final Thoughts**
This method is the most **efficient** for solving LeetCode 442. It avoids extra space while keeping the time complexity at **O(n)**, making it suitable for large input sizes up to `10^5`.

---
Happy Coding! 🚀

