// LC 448: Find All Numbers Disappeared in an Array
// Pattern: Index Marking / Cyclic Sort
// Time: O(n) | Space: O(1)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Approach 1: Negative marking
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    
    // Mark indices as negative
    for (int i = 0; i < n; i++) {
        int idx = abs(nums[i]) - 1;
        nums[idx] = -abs(nums[idx]);
    }
    
    // Collect unmarked indices
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }
    
    return result;
}

// Approach 2: Cyclic sort
vector<int> findDisappearedNumbersCyclic(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    auto result = findDisappearedNumbers(nums);
    cout << "Disappeared numbers: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
