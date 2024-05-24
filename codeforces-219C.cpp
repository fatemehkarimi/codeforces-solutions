//https://codeforces.com/problemset/problem/219/C
//C. Color Stripe

#include <iostream>
#include <climits>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    string input;
    cin >> input;

    vector <vector <int> > dp(n, vector <int> (k, INT_MAX));
    vector <vector <int> > parent(n, vector <int> (k, -1));

    for(int i = 0; i < k; ++i)
        if(i == input[0] - 'A')
            dp[0][i] = 0;
        else
            dp[0][i] = 1;

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < k; ++j){
            int min_pre = INT_MAX, min_pre_idx;
            for(int m = 0; m < k; ++m)
                if(j != m && dp[i - 1][m] < min_pre){
                    min_pre = dp[i - 1][m];
                    min_pre_idx = m;
                }

            dp[i][j] = (j == input[i] - 'A' ? min_pre : min_pre + 1);
            parent[i][j] = min_pre_idx;
        }

    int result = INT_MAX;
    int curr;
    for(int i = 0; i < k; ++i)
        if(dp[n - 1][i] < result){
            result = dp[n - 1][i];
            curr = i;
        }

    for(int i = n - 1; i >= 0; --i){
        input[i] = (char)('A' + curr);
        curr = parent[i][curr];
    }

    cout << result << endl;
    cout << input << endl;
    return 0;
}
