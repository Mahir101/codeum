// LC 229: Majority Element II | LC 1287: Element Appearing > 25%
#include <iostream>
#include <vector>
using namespace std;

// LC 229: Elements appearing > n/3 times (at most 2)
vector<int> majorityElementII(vector<int>& nums) {
    int cand1 = 0, cand2 = 0, cnt1 = 0, cnt2 = 0;
    for (int n : nums) {
        if (n == cand1) cnt1++;
        else if (n == cand2) cnt2++;
        else if (cnt1 == 0) { cand1 = n; cnt1 = 1; }
        else if (cnt2 == 0) { cand2 = n; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }
    cnt1 = cnt2 = 0;
    for (int n : nums) { if (n == cand1) cnt1++; else if (n == cand2) cnt2++; }
    vector<int> result;
    if (cnt1 > (int)nums.size() / 3) result.push_back(cand1);
    if (cnt2 > (int)nums.size() / 3) result.push_back(cand2);
    return result;
}

// LC 1287: Element Appearing More Than 25%
int findSpecialInteger(vector<int>& arr) {
    int n = arr.size(), quarter = n / 4;
    for (int i = 0; i + quarter < n; i++)
        if (arr[i] == arr[i + quarter]) return arr[i];
    return arr.back();
}

int main() {
    vector<int> nums = {3, 2, 3};
    auto result = majorityElementII(nums);
    cout << "Majority II: "; for (int x : result) cout << x << " "; cout << endl;
    return 0;
}
