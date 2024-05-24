//https://codeforces.com/problemset/problem/332/B
//B. Maximum Absurdity

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

    vector <long long int> sums(1);
    for(int i = 0; i < k; ++i)
        sums[0] += nums[i];

    for(int i = 1; i < n - k + 1; ++i){
        long long int sum = sums[i - 1] + nums[i + k - 1] - nums[i - 1];
        sums.push_back(sum);
    }

    int n_intervals = sums.size();
    vector <pair <long long int, int> > maximum_behind(n_intervals, make_pair(-1, -1));
    for(int i = 0; i < n_intervals; ++i)
        if(i - k >= 0){
            if(maximum_behind[i - 1].first < sums[i - k])
                maximum_behind[i] = make_pair(sums[i - k], i - k);
            else
                maximum_behind[i] = maximum_behind[i - 1];
    }

    vector <pair <long long int, int> > maximum_forward(n_intervals, make_pair(-1, -1));
    for(int i = n_intervals - 1; i >= 0; --i)
        if(i + k < n_intervals){
            if(maximum_forward[i + 1].first <= sums[i + k])
                maximum_forward[i] = make_pair(sums[i + k], i + k);
            else
                maximum_forward[i] = maximum_forward[i + 1];
        }

    int result_index = 0;
    for(int i = 0; i < n_intervals; ++i)
        if(sums[result_index] + max(maximum_forward[result_index].first, maximum_forward[result_index].first)
            < sums[i] + max(maximum_forward[i].first, maximum_forward[i].first))
            result_index = i;

    int index1 = result_index;
    int index2 = (maximum_forward[index1].first > maximum_behind[index1].first ? maximum_forward[index1].second : maximum_behind[index1].second);

    cout << min(index1, index2) + 1 << ' ' << max(index1, index2) + 1 << endl;
    return 0;
}
