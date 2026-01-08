// LC 363: Max Sum of Rectangle No Larger Than K
// LC 1074: Number of Submatrices That Sum to Target
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// LC 363: Max Sum Rectangle <= K
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int maxSum = INT_MIN;
    
    for (int left = 0; left < n; left++) {
        vector<int> rowSum(m, 0);
        for (int right = left; right < n; right++) {
            for (int i = 0; i < m; i++) rowSum[i] += matrix[i][right];
            
            set<int> prefixSet = {0};
            int prefix = 0;
            for (int sum : rowSum) {
                prefix += sum;
                auto it = prefixSet.lower_bound(prefix - k);
                if (it != prefixSet.end()) maxSum = max(maxSum, prefix - *it);
                prefixSet.insert(prefix);
            }
        }
    }
    return maxSum;
}

// LC 1074: Number of Submatrices Sum to Target
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), count = 0;
    
    for (int left = 0; left < n; left++) {
        vector<int> rowSum(m, 0);
        for (int right = left; right < n; right++) {
            for (int i = 0; i < m; i++) rowSum[i] += matrix[i][right];
            
            unordered_map<int, int> prefixCount = {{0, 1}};
            int prefix = 0;
            for (int sum : rowSum) {
                prefix += sum;
                count += prefixCount[prefix - target];
                prefixCount[prefix]++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> matrix = {{1,0,1},{0,-2,3}};
    cout << "Max sum <= 2: " << maxSumSubmatrix(matrix, 2) << endl;
    return 0;
}
