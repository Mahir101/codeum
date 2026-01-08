// LC 853: Car Fleet
// Pattern: Stack for Collision Simulation
// Time: O(n log n) | Space: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int, double>> cars(n);
    
    for (int i = 0; i < n; i++) {
        cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
    }
    
    sort(cars.begin(), cars.end());  // Sort by position
    
    int fleets = 0;
    double slowest = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (cars[i].second > slowest) {
            fleets++;
            slowest = cars[i].second;
        }
    }
    
    return fleets;
}

int main() {
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << "Car fleets: " << carFleet(12, position, speed) << endl;
    return 0;
}
