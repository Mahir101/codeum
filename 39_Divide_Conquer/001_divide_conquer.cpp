// Divide and Conquer Pattern
// LC 148: Sort List | LC 912: Sort Array | LC 4: Median of Two Arrays
// LC 315: Count of Smaller Numbers After Self
#include <iostream>
#include <vector>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(nullptr) {} };

// LC 148: Sort List (Merge Sort for Linked List)
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    ListNode* mid = slow->next; slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

// LC 315: Count of Smaller Numbers After Self (Merge Sort)
void mergeCount(vector<pair<int, int>>& arr, int lo, int hi, vector<int>& count) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    mergeCount(arr, lo, mid, count);
    mergeCount(arr, mid + 1, hi, count);
    
    vector<pair<int, int>> merged;
    int i = lo, j = mid + 1, rightCount = 0;
    while (i <= mid && j <= hi) {
        if (arr[j].first < arr[i].first) { rightCount++; merged.push_back(arr[j++]); }
        else { count[arr[i].second] += rightCount; merged.push_back(arr[i++]); }
    }
    while (i <= mid) { count[arr[i].second] += rightCount; merged.push_back(arr[i++]); }
    while (j <= hi) merged.push_back(arr[j++]);
    for (int k = lo; k <= hi; k++) arr[k] = merged[k - lo];
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n, 0);
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
    mergeCount(arr, 0, n - 1, count);
    return count;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};
    auto result = countSmaller(nums);
    cout << "Count smaller: "; for (int x : result) cout << x << " "; cout << endl;
    return 0;
}
