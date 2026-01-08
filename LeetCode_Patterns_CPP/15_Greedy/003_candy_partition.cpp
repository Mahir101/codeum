// LC 135: Candy | LC 763: Partition Labels
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC 135: Candy (two pass greedy)
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
    int sum = 0;
    for (int c : candies) sum += c;
    return sum;
}

// LC 763: Partition Labels
vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);
    for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;
    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) { result.push_back(end - start + 1); start = i + 1; }
    }
    return result;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    cout << "Min candies: " << candy(ratings) << endl;
    return 0;
}
