//https://codeforces.com/problemset/problem/814/C
//C. An impassioned circulation of affection

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string input;
    cin >> input;

    vector < vector < vector <int> > > dp(26, vector < vector <int> > (n + 1, vector <int> (n, 0)));

    for(int i = 0; i < (int)input.size(); ++i)
        if(i > 0 && input[i] - 'a' == input[i - 1] - 'a')
            dp[input[i] - 'a'][0][i] = dp[input[i] - 'a'][0][i - 1] + 1;
        else
            dp[input[i] - 'a'][0][i] = 1;

    for(int i = 0; i < 26; ++i)
        for(int j = 1; j < n + 1; ++j)
            dp[i][j][0] = 1;

    for(int i = 0; i < 26; ++i)
        for(int j = 1; j < n + 1; ++j)
            for(int k = 1; k < n; ++k)
                if((int)(input[k] - 'a') == i)
                    dp[i][j][k] = dp[i][j][k - 1] + 1;
                else
                    dp[i][j][k] = dp[i][j - 1][k - 1] + 1;

    int q;
    cin >> q;
    while(q--){
        int m;
        char c;
        cin >> m >> c;
        int idx = c - 'a';

        if(m >= n){
            cout << n << endl;
            continue;
        }
        int result = *max_element(dp[idx][m].begin(), dp[idx][m].end());
        cout << result << endl;
    }
    return 0;
}
