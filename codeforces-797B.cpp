//https://codeforces.com/problemset/problem/797/B
//B. Odd sum

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    int max_odd_value = INT_MIN;
    int total_sum = 0;

    for(int i = 0; i < n; ++i)
        if(nums[i] > 0)
            total_sum += nums[i];

    if(total_sum % 2 == 0){
        for(int i = 0; i < n; ++i)
            if(nums[i] < 0 && abs(nums[i]) % 2)
                max_odd_value = max(max_odd_value, total_sum + nums[i]);
            else if(nums[i] > 0 && nums[i] % 2)
                max_odd_value = max(max_odd_value, total_sum - nums[i]);
    }
    else
        max_odd_value = total_sum;

    cout << max_odd_value << endl;
    return 0;
}

