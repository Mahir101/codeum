// LC 496: Next Greater Element I
// Pattern: Monotonic Stack with HashMap
// Time: O(n+m) | Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> stk;
    
    for (int num : nums2) {
        while (!stk.empty() && stk.top() < num) {
            nextGreater[stk.top()] = num;
            stk.pop();
        }
        stk.push(num);
    }
    
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
    }
    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    auto result = nextGreaterElement(nums1, nums2);
    cout << "Next greater: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
