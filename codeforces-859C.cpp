//https://codeforces.com/problemset/problem/859/C
//C. Pie Rules

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    std::reverse(nums.begin(), nums.end());
    long long int B_share = 0;
    long long int total_sum = 0;
    for(int i = 0; i < n; ++i){
        total_sum += nums[i];
        B_share = max(B_share, total_sum - B_share);
    }

    cout << total_sum - B_share << ' ' << B_share << endl;
    return 0;
}
