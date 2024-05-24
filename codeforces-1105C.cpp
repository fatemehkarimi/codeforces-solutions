//https://codeforces.com/problemset/problem/1105/C
//C. Ayoub and Lost Array

#include <iostream>
#include <vector>

#define MODULO 1000000007
using namespace std;

int main(void)
{
    int n, l, r;
    cin >> n >> l >> r;

    int arr[3] = {0, 0, 0};
    for(int i = l; i <= min(l + 2, r); ++i)
        arr[i % 3] = i;
    for(int i = r; i >= max(r - 2, l); --i)
        arr[i % 3] = (i - arr[i % 3]) / 3 + 1;

    vector < vector <long long int> > dp(3, vector <long long int> (n + 1, 0));
    dp[0][1] = arr[0], dp[1][1] = arr[1], dp[2][1] = arr[2];

    for(int i = 2; i <= n; ++i)
        for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 3; ++k){
                long long int tmp = arr[k] * dp[((j - k) + 3) % 3][i - 1];
                tmp %= MODULO;
                dp[j][i] += tmp;
                dp[j][i] %= MODULO;
            }

    cout << dp[0][n] << endl;
    return 0;
}
