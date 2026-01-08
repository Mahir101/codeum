// LC 403: Frog Jump | LC 1306: Jump Game III
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// LC 403: Frog Jump (DP with memoization)
bool canCross(vector<int>& stones) {
    unordered_map<int, int> stoneIdx;
    for (int i = 0; i < (int)stones.size(); i++) stoneIdx[stones[i]] = i;
    
    int n = stones.size();
    vector<unordered_set<int>> dp(n);  // dp[i] = possible jump sizes to reach stone i
    dp[0].insert(0);
    
    for (int i = 0; i < n; i++) {
        for (int k : dp[i]) {
            for (int jump : {k - 1, k, k + 1}) {
                if (jump > 0 && stoneIdx.count(stones[i] + jump)) {
                    int next = stoneIdx[stones[i] + jump];
                    if (next == n - 1) return true;
                    dp[next].insert(jump);
                }
            }
        }
    }
    return !dp[n - 1].empty();
}

// LC 1306: Jump Game III (BFS)
bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    q.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;
    
    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (arr[i] == 0) return true;
        for (int next : {i + arr[i], i - arr[i]}) {
            if (next >= 0 && next < n && !visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

// LC 45: Jump Game II (Greedy)
int jump(vector<int>& nums) {
    int jumps = 0, currEnd = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd) { jumps++; currEnd = farthest; }
    }
    return jumps;
}

int main() {
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << "Can cross: " << canCross(stones) << endl;
    return 0;
}
