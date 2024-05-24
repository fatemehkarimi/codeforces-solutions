//http://codeforces.com/problemset/problem/580/A
//A. Kefa and First Steps

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;

    vector <int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector <int> length(n, 1);

    for (int i = 1; i < n; ++i)
        if (nums[i - 1] <= nums[i])
            length[i] = length[i - 1] + 1;

    int max_length = 1;
    for (auto a : length)
        if (a > max_length)
            max_length = a;

    cout << max_length << endl;

    return 0;
}
