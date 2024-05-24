//https://codeforces.com/problemset/problem/313/C
//C. Ilya and Matrix

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <long long int> nums(n);
    for(int i = 0; i < n; ++i)
        scanf("%I64d", &nums[i]);

    sort(nums.rbegin(), nums.rend());
    for(int i = 1; i < n; ++i)
        nums[i] = nums[i - 1] + nums[i];

    long long int total = 0;
    for(int i = 1;i <= n; i *= 4)
        total += nums[i - 1];
    cout << total << endl;
    return 0;
}
