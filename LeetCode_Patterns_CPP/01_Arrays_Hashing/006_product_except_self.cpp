// LC 238: Product of Array Except Self
// Pattern: Prefix/Suffix Product
// Time: O(n) | Space: O(1) excluding output
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    // Left products
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Right products
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    auto result = productExceptSelf(nums);
    cout << "Product except self [1,2,3,4]: ";
    for (int n : result) cout << n << " ";
    cout << endl;
    return 0;
}
