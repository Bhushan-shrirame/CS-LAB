#include<bits/stdc++.h>
using namespace std;
int unsorted_max_elements(vector<int> nums, int w)
{
    int i, count = 0;
    const int limit = 10000;
    vector<int> freq(2 * limit + 1, 0);
    for (auto i : nums)
    {
        freq[i + limit]++;
    }
    for (i = -limit; i <= limit; i++)
    {
        if (freq[i + limit] > 0)
        {
            while (freq[i + limit] > 0 && i <= w)
            {
                w -= i;
                freq[i + limit]--;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, w, val;
    vector<int> nums;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }
    cout << "Enter the value of w: ";
    cin >> w;
    cout << "Maximum number of elements of A that can be selected from unsorted array is ";
    cout << unsorted_max_elements(nums, w) << endl;
    return 0;
}