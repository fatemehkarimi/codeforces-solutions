//https://codeforces.com/problemset/problem/961/B
//B. Lecture Sleep

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector <int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    vector <int> sleep(n);
    for(int i = 0; i < n; ++i)
        cin >> sleep[i];

    vector <int> sum(n, 0);
    if(!sleep[0])
        sum[0] = nums[0];

    for(int i = 1; i < n; ++i)
        sum[i] = sum[i - 1] + (sleep[i] ? 0 : nums[i]); 

    int result = 0;
    for(int i = 0; i < n; ++i){
        int tmp = sum[(i + k - 1 < n ? i + k - 1 : n - 1)] - (i - 1 >= 0 ? sum[i - 1] : 0);
        result = max(result, tmp);
    }

    for(int i = 0; i < n; ++i)
        if(sleep[i])
            result += nums[i];

    cout << result << endl;
    return 0;
}
