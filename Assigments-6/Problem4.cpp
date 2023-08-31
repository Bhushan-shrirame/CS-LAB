#include <bits/stdc++.h>
using namespace std;


int solution(vector<int> &nums)
{
    int n = nums.size();
    int sm = 0;
    int maxMin = INT_MIN;
    int minMax = INT_MAX;
    int maxINC = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int diff = abs(nums[i] - nums[i - 1]);
        sm += diff;
        maxMin = max(maxMin, min(nums[i - 1], nums[i]));
        minMax = min(minMax, max(nums[i - 1], nums[i]));
        maxINC = max(maxINC, abs(nums[0] - nums[i]) - diff);
        maxINC = max(maxINC, abs(nums[n - 1] - nums[i - 1]) - diff);
    }
    maxINC = max(maxINC, 2 * (maxMin - minMax));
    return sm + maxINC;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        int maxScore = 0;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cout << solution(arr) << endl;
    }
}