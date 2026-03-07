// LC 264: Ugly Number II | K-way merge for sequences
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// LC 264: Ugly Number II (merge 3 sequences)
int nthUglyNumber(int n) {
    vector<long> ugly(n);
    ugly[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    
    for (int i = 1; i < n; i++) {
        long next2 = ugly[p2] * 2;
        long next3 = ugly[p3] * 3;
        long next5 = ugly[p5] * 5;
        ugly[i] = min({next2, next3, next5});
        if (ugly[i] == next2) p2++;
        if (ugly[i] == next3) p3++;
        if (ugly[i] == next5) p5++;
    }
    return ugly[n - 1];
}

// LC 313: Super Ugly Number (k primes)
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    vector<long> ugly(n), idx(k, 0);
    ugly[0] = 1;
    
    for (int i = 1; i < n; i++) {
        long minVal = LONG_MAX;
        for (int j = 0; j < k; j++) {
            minVal = min(minVal, ugly[idx[j]] * primes[j]);
        }
        ugly[i] = minVal;
        for (int j = 0; j < k; j++) {
            if (ugly[idx[j]] * primes[j] == minVal) idx[j]++;
        }
    }
    return ugly[n - 1];
}

// LC 786: K-th Smallest Prime Fraction
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<>> pq;
    for (int i = 0; i < n - 1; i++) pq.push({(double)arr[i] / arr[n-1], i, n-1});
    
    while (--k > 0) {
        auto [_, i, j] = pq.top(); pq.pop();
        if (j - 1 > i) pq.push({(double)arr[i] / arr[j-1], i, j-1});
    }
    auto [_, i, j] = pq.top();
    return {arr[i], arr[j]};
}

int main() {
    cout << "10th ugly number: " << nthUglyNumber(10) << endl;
    return 0;
}
