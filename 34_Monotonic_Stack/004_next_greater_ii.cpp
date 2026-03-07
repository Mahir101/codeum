// LC 503: Next Greater Element II | LC 1019: Next Greater Node In Linked List
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 503: Next Greater Element II (Circular)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;
    
    for (int i = 0; i < 2 * n; i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
            result[stk.top()] = nums[i % n];
            stk.pop();
        }
        if (i < n) stk.push(i);
    }
    return result;
}

// LC 1019: Next Greater Node In Linked List
vector<int> nextLargerNodes(ListNode* head) {
    vector<int> nums;
    for (ListNode* n = head; n; n = n->next) nums.push_back(n->val);
    
    int m = nums.size();
    vector<int> result(m, 0);
    stack<int> stk;
    
    for (int i = 0; i < m; i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i]) {
            result[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    return result;
}

// Stock Span Problem
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> stk;
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && prices[stk.top()] <= prices[i]) stk.pop();
        span[i] = stk.empty() ? i + 1 : i - stk.top();
        stk.push(i);
    }
    return span;
}

int main() {
    vector<int> nums = {1, 2, 1};
    auto result = nextGreaterElements(nums);
    cout << "Next greater II: "; for (int x : result) cout << x << " "; cout << endl;
    return 0;
}
