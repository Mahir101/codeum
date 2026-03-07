// LC 179: Largest Number | LC 1029: Two City Scheduling
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LC 179: Largest Number from array
string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int n : nums) strs.push_back(to_string(n));
    sort(strs.begin(), strs.end(), [](string& a, string& b) { return a + b > b + a; });
    if (strs[0] == "0") return "0";
    string result;
    for (auto& s : strs) result += s;
    return result;
}

// LC 1029: Two City Scheduling
int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
        return (a[0] - a[1]) < (b[0] - b[1]);
    });
    int n = costs.size() / 2, total = 0;
    for (int i = 0; i < n; i++) total += costs[i][0] + costs[i + n][1];
    return total;
}

// LC 406: Queue Reconstruction by Height
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](auto& a, auto& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    vector<vector<int>> result;
    for (auto& p : people) result.insert(result.begin() + p[1], p);
    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << "Largest number: " << largestNumber(nums) << endl;
    return 0;
}
