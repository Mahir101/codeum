// LC 287: Find Duplicate (array as linked list)
// LC 765: Couples Holding Hands (cycle detection in permutation)
#include <iostream>
#include <vector>
using namespace std;

// Find Duplicate - treating array values as pointers
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do { slow = nums[slow]; fast = nums[nums[fast]]; } while (slow != fast);
    slow = nums[0];
    while (slow != fast) { slow = nums[slow]; fast = nums[fast]; }
    return slow;
}

// LC 765: Minimum Swaps for Couples (Cyclic)
int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[row[i]] = i;
    int swaps = 0;
    for (int i = 0; i < n; i += 2) {
        int partner = row[i] ^ 1;  // XOR to get partner
        if (row[i + 1] != partner) {
            int j = pos[partner];
            swap(row[i + 1], row[j]);
            pos[row[j]] = j;
            pos[row[i + 1]] = i + 1;
            swaps++;
        }
    }
    return swaps;
}

// Find All Duplicates in range [1, n]
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) result.push_back(idx + 1);
        else nums[idx] = -nums[idx];
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate: " << findDuplicate(nums) << endl;
    return 0;
}
