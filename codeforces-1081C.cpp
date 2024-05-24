//https://codeforces.com/problemset/problem/1081/C
//C. Colorful Bricks

#include <iostream>
#include <vector>

#define MODULO 998244353
using namespace std;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <vector <int> > dp(k + 1, vector <int> (n));
    for(int i = 0; i < n; ++i)
        dp[0][i] = m;

    for(int i = 1; i <= k; ++i)
        for(int j = 1; j < n; ++j)
            dp[i][j] = ((long long int)(m - 1) * dp[i - 1][j - 1] % MODULO + dp[i][j - 1]) % MODULO;
    cout << dp[k][n - 1] << endl;
    return 0;
}
