// LC 1109: Corporate Flight Bookings | LC 370: Range Addition
#include <iostream>
#include <vector>
using namespace std;

// LC 1109: Corporate Flight Bookings (Difference Array)
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 1, 0);
    for (auto& b : bookings) {
        diff[b[0] - 1] += b[2];
        diff[b[1]] -= b[2];
    }
    vector<int> result(n);
    result[0] = diff[0];
    for (int i = 1; i < n; i++) result[i] = result[i-1] + diff[i];
    return result;
}

// LC 370: Range Addition (same pattern)
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> diff(length + 1, 0);
    for (auto& u : updates) {
        diff[u[0]] += u[2];
        diff[u[1] + 1] -= u[2];
    }
    vector<int> result(length);
    result[0] = diff[0];
    for (int i = 1; i < length; i++) result[i] = result[i-1] + diff[i];
    return result;
}

// LC 1094: Car Pooling
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001, 0);
    for (auto& t : trips) {
        diff[t[1]] += t[0];
        diff[t[2]] -= t[0];
    }
    int curr = 0;
    for (int d : diff) {
        curr += d;
        if (curr > capacity) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    auto result = corpFlightBookings(bookings, 5);
    cout << "Flight bookings: "; for (int x : result) cout << x << " "; cout << endl;
    return 0;
}
