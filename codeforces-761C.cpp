//https://codeforces.com/problemset/problem/761/C
//C. Dasha and Password

#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector <string> password(n);
    for(int i = 0; i < n; ++i)
        cin >> password[i];

    vector < vector <int> > min_loc(n, vector <int> (3, INT_MAX));//letter, digit, symbol

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            int dis1 = j;
            int dis2 = abs(m - 1 - j) + 1;
            if(password[i][j] >= '0' && password[i][j] <= '9')
                min_loc[i][0] = min(min_loc[i][0], min(dis1, dis2));
            else if(password[i][j] >= 'a' && password[i][j] <= 'z')
                min_loc[i][1] = min(min_loc[i][1], min(dis1, dis2));
            else
                min_loc[i][2] = min(min_loc[i][2], min(dis1, dis2));
        }

    vector <int> dp(n, INT_MAX);
    for(int i = 0; i < n; ++i)//set all to their digit value at the begining
        dp[i] = min_loc[i][0];

    for(int k = 1; k < 3; ++k){
        vector <int> tmp_dp(n, INT_MAX);
        for(int i = 0; i < n; ++i){
            int min_pre = INT_MAX, min_k = INT_MAX;
            for(int j = 0; j < n; ++j)
                if(i != j)
                    min_pre = min(min_pre, dp[j]);

            for(int j = 0; j < n; ++j)
                if(i != j)
                    min_k = min(min_k, min_loc[j][k]);

            if(min_loc[i][k] != INT_MAX && min_pre != INT_MAX)
                tmp_dp[i] = min_loc[i][k] + min_pre;
            if(dp[i] != INT_MAX && min_k != INT_MAX)
                tmp_dp[i] = min(tmp_dp[i], dp[i] + min_k);
        }

        dp = tmp_dp;
    }

    int result = INT_MAX;
    for(auto a : dp)
        result = min(result, a);
    cout << result << endl;
    return 0;
}
