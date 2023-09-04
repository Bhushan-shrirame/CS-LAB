#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool backtrack(vector<int>& nums, vector<vector<int>>& subsets, unordered_map<int, int>& count, int targetSum, int K, int currentSum, int startIndex) {
    if (K == 0) {
        return true;
    }

    if (currentSum == targetSum) {
        return backtrack(nums, subsets, count, targetSum, K - 1, 0, 0);
    }

    for (int i = startIndex; i < nums.size(); i++) {
        if (count[nums[i]] > 0 && currentSum + nums[i] <= targetSum) {
            count[nums[i]]--;
            subsets[K - 1].push_back(nums[i]);

            if (backtrack(nums, subsets, count, targetSum, K, currentSum + nums[i], i + 1)) {
                return true;
            }

            count[nums[i]]++;
            subsets[K - 1].pop_back();
        }
    }

    return false;
}

vector<vector<int>> canPartitionKSubsets(vector<int>& nums, int K) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % K != 0) {
        return {};
    }

    int targetSum = totalSum / K;
    unordered_map<int, int> count;
    vector<vector<int>> subsets(K, vector<int>());
    
    for (int num : nums) {
        count[num]++;
    }

    bool canPartition = backtrack(nums, subsets, count, targetSum, K, 0, 0);

    return canPartition ? subsets : vector<vector<int>>();
}

int main() {
	int n , a;
	cin >> n;

    vector<int> nums;
    int K = 4;
	for(int i=0 ; i<n ; i++)
    {
        cin>>a;
        nums.push_back(a);
    }

    vector<vector<int>> result = canPartitionKSubsets(nums, K);

    if (result.empty()) {
        cout << "It is not possible to divide the array into " << K << " subsets with the same sum." << endl;
    } else {
        cout << "Possible subsets with the same sum:" << endl;
        for (const vector<int>& subset : result) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
	
}
//  4 3 2 3 5 2 1

