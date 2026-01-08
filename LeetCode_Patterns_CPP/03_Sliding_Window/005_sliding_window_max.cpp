// LC 239: Sliding Window Maximum | Pattern: Monotonic Deque
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < (int)nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // Remove smaller elements (they'll never be max)
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto result = maxSlidingWindow(nums, 3);
    cout << "Sliding max (k=3): ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
