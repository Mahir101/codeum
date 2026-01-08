// LC 621: Task Scheduler | LC 358: Rearrange String k Distance
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// LC 621: Task Scheduler (greedy)
int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    int maxFreq = 0, maxCount = 0;
    for (char t : tasks) {
        freq[t - 'A']++;
        if (freq[t - 'A'] > maxFreq) { maxFreq = freq[t - 'A']; maxCount = 1; }
        else if (freq[t - 'A'] == maxFreq) maxCount++;
    }
    int partCount = maxFreq - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasks.size() - maxFreq * maxCount;
    int idles = max(0, emptySlots - availableTasks);
    return tasks.size() + idles;
}

// LC 358: Rearrange String k Distance Apart
string rearrangeString(string s, int k) {
    if (k == 0) return s;
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto& [c, f] : freq) pq.push({f, c});
    
    string result;
    queue<pair<int, char>> waitQueue;
    
    while (!pq.empty()) {
        auto [f, c] = pq.top(); pq.pop();
        result += c;
        waitQueue.push({f - 1, c});
        if ((int)waitQueue.size() >= k) {
            auto [wf, wc] = waitQueue.front(); waitQueue.pop();
            if (wf > 0) pq.push({wf, wc});
        }
    }
    return result.size() == s.size() ? result : "";
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << "Least interval n=2: " << leastInterval(tasks, 2) << endl;
    return 0;
}
