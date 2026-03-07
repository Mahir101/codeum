// LC 1095: Find in Mountain Array | LC 702: Search in Sorted Array of Unknown Size
#include <iostream>
#include <vector>
using namespace std;

// Mountain Array Interface
class MountainArray {
    vector<int> arr = {1, 2, 3, 4, 5, 3, 1};
public:
    int get(int index) { return arr[index]; }
    int length() { return arr.size(); }
};

// LC 1095: Find in Mountain Array
int findInMountainArray(int target, MountainArray& mountainArr) {
    int n = mountainArr.length();
    
    // Find peak
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) lo = mid + 1;
        else hi = mid;
    }
    int peak = lo;
    
    // Search left side (ascending)
    lo = 0; hi = peak;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = mountainArr.get(mid);
        if (val == target) return mid;
        if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    
    // Search right side (descending)
    lo = peak; hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = mountainArr.get(mid);
        if (val == target) return mid;
        if (val > target) lo = mid + 1;
        else hi = mid - 1;
    }
    
    return -1;
}

// LC 702: Search in infinite sorted array
int searchInfinite(vector<int>& reader, int target) {
    int lo = 0, hi = 1;
    while (reader[hi] < target) { lo = hi; hi *= 2; }
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (reader[mid] == target) return mid;
        if (reader[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    MountainArray ma;
    cout << "Find 3 in mountain: " << findInMountainArray(3, ma) << endl;
    return 0;
}
