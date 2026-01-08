// LC 503: Next Greater Element II (Circular)
// Pattern: Monotonic Stack with Circular Array
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;
    
    // Traverse array twice for circular behavior
    for (int i = 0; i < 2 * n; i++) {
        while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
            result[stk.top()] = nums[i % n];
            stk.pop();
        }
        if (i < n) stk.push(i);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    auto result = nextGreaterElements(nums);
    cout << "Next greater (circular): ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
