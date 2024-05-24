//https://codeforces.com/problemset/problem/717/C
//Potions Homework

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    long long int n;
    cin >> n;

    vector <long long int> nums(n);

    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    long long int min_sum = 0;
    sort(nums.begin(), nums.end());

    long long int i = 0, j = n - 1;

    for(; i < n; ++i)
        min_sum += (nums[i] * nums[j--]);

    cout << min_sum % 10007 << endl;
    return 0;
}
