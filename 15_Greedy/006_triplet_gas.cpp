// LC 334: Increasing Triplet Subsequence | LC 134: Gas Station
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// LC 334: Increasing Triplet Subsequence
bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    for (int n : nums) {
        if (n <= first) first = n;
        else if (n <= second) second = n;
        else return true;
    }
    return false;
}

// LC 134: Gas Station (circular, find start)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, curr = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        total += gas[i] - cost[i];
        curr += gas[i] - cost[i];
        if (curr < 0) { start = i + 1; curr = 0; }
    }
    return total >= 0 ? start : -1;
}

// LC 1578: Minimum Time to Make Rope Colorful
int minCost(string colors, vector<int>& neededTime) {
    int total = 0, maxTime = 0;
    for (int i = 0; i < (int)colors.size(); i++) {
        if (i > 0 && colors[i] != colors[i-1]) maxTime = 0;
        total += min(maxTime, neededTime[i]);
        maxTime = max(maxTime, neededTime[i]);
    }
    return total;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Has triplet: " << increasingTriplet(nums) << endl;
    return 0;
}
