// Cyclic Sort Pattern - Numbers in range [1, n] in array of size n
// LC 268: Missing Number | LC 448: Find Disappeared | LC 287: Find Duplicate
// LC 41: First Missing Positive | LC 442: Find All Duplicates
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Core Pattern: Place each number at index = number - 1
void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < (int)nums.size()) {
        int correct = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= (int)nums.size() && nums[i] != nums[correct])
            swap(nums[i], nums[correct]);
        else i++;
    }
}

// LC 268: Missing Number
int missingNumber(vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        if (nums[i] < n && nums[i] != nums[nums[i]]) swap(nums[i], nums[nums[i]]);
        else i++;
    }
    for (int i = 0; i < n; i++) if (nums[i] != i) return i;
    return n;
}

// LC 448: Find All Numbers Disappeared
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0, n = nums.size();
    while (i < n) {
        int j = nums[i] - 1;
        if (nums[i] != nums[j]) swap(nums[i], nums[j]);
        else i++;
    }
    vector<int> result;
    for (int i = 0; i < n; i++) if (nums[i] != i + 1) result.push_back(i + 1);
    return result;
}

// LC 442: Find All Duplicates
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) result.push_back(idx + 1);
        else nums[idx] = -nums[idx];
    }
    return result;
}

int main() { cout << "Cyclic Sort Pattern\n"; return 0; }
