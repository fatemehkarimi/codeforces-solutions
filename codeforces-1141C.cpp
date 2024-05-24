//https://codeforces.com/problemset/problem/1141/C
//C. Polycarp Restores Permutation

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <long long int> diffs(n - 1);
    long long int limit_min = INT_MAX;
    long long int limit_max = INT_MIN;
    long long int total_sum = 0;
    for(int i = 1; i < n; ++i){
        cin >> diffs[i - 1];
        total_sum += diffs[i - 1];
        limit_min = min(limit_min, total_sum);
        limit_max = max(limit_max, total_sum);
    }

    long long int start = abs(limit_max) > abs(limit_min) ? limit_max : limit_min;
    if(start < 0)
        start = 1 - start;
    else
        start = n - start;

    if(start < 1 || start > n){
        cout << -1 << endl;
        return 0;
    }
    bool valid = 1;
    vector <long long int> result(n);
    vector <bool> used(n + 1, 0);

    result[0] = start;
    used[start] = true;

    for(int i = 1; i < n; ++i){
        int next = result[i - 1] + diffs[i - 1];
        if(next >= 1 && next <= n && !used[next]){
            result[i] = next;
            used[next] = true;
        } 
        else
            valid = false;
    }

    if(valid){
        for(auto a : result)
            cout << a << ' ';
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
