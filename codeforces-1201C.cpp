//https://codeforces.com/problemset/problem/1201/C
//C. Maximum Median

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int find_greater(vector <int> & nums, int left, int right, int value)
{
    if(left >= right)
        return INT_MAX;
    int middle = left + (right - left) / 2;
    if(value < nums[middle])
        return min(middle, find_greater(nums, left, middle, value));
    else
        return find_greater(nums, middle + 1, right, value);
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector <int> nums(n);

    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    int middle = n / 2;

    int left = middle;
    while(true){
        int next = find_greater(nums, left, n, nums[left]);
        if(next == INT_MAX)
            break;
        int value = min(nums[next] - nums[middle], k / (next - middle));
        nums[middle] += value;
        k -= (value * (next - middle));
        left = next;
    }
    nums[middle] += (k / (middle + 1));
    cout << nums[middle] << endl;
    return 0;
}
