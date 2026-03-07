// LC 621: Task Scheduler | Pattern: Greedy with Cooldown
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char t : tasks) freq[t - 'A']++;
    int maxFreq = *max_element(freq.begin(), freq.end());
    int maxCount = count(freq.begin(), freq.end(), maxFreq);
    int gaps = maxFreq - 1;
    int gapLen = n - (maxCount - 1);
    int availableSlots = gaps * max(0, gapLen);
    int remainingTasks = tasks.size() - maxFreq * maxCount;
    int idles = max(0, availableSlots - remainingTasks);
    return tasks.size() + idles;
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << "Least interval (n=2): " << leastInterval(tasks, 2) << endl;
    return 0;
}
