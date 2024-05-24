//https://codeforces.com/problemset/problem/913/C
//C. Party Lemonade

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

#define lld long long int

using namespace std;

int main(void)
{
    lld n, l;
    cin >> n >> l;
    vector <lld> costs(n);
    for(int i = 0; i < n; ++i)
        cin >> costs[i];

    vector <lld> dp;
    lld pow_ = 0, pow_value = 1;
    bool fin = false;
    while(!fin){
        if(pow_value >= l && pow_ >= n - 1)
            fin = 1;

        lld cost_pow = (pow_ < n ? costs[pow_] : LLONG_MAX);
        cost_pow = min(cost_pow, (lld)dp.size() > 0 ? dp.back() * 2 : LLONG_MAX);
        dp.push_back(cost_pow);
        ++pow_;
        pow_value *= 2;
    }
    --pow_;
    pow_value /= 2;
    lld min_cost = 0;
    lld result = dp.back();
    while(l > 0){
        lld factor = l / pow_value;
        if(factor == 0)
            result = min(result, min_cost + dp[pow_]);
        l -= factor * pow_value;
        min_cost += factor * dp[pow_];
        --pow_;
        pow_value /= 2;
    }
    cout << min(min_cost, result) << endl;
    return 0;
}
