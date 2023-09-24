#include <bits/stdc++.h>
using namespace std;

int robLinear(vector<int>& nums) {
    int prev = 0, curr = 0;
    for (int num : nums) {
        int temp = curr;
        curr = max(prev + num, curr);
        prev = temp;
    }
    return curr;
}

int robCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }

    // Case 1: Rob the first house and don't rob the last house
    vector<int> nums1(nums.begin(), nums.end() - 1);
    int result1 = robLinear(nums1);

    // Case 2: Don't rob the first house and consider robbing the last house
    vector<int> nums2(nums.begin() + 1, nums.end());
    int result2 = robLinear(nums2);

    // Return the maximum of the two cases
    return max(result1, result2);
}

int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter the values of each house: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = robCircular(nums);
    cout << "Maximum amount you can rob: " << result << endl;

    return 0;
}
