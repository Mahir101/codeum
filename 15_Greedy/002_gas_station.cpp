// LC 134: Gas Station | Pattern: Greedy with Reset
// Time: O(n) | Space: O(1)
// Recognition: "Find starting point for circular route"
#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) { start = i + 1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}

int main() {
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    cout << "Start station: " << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
