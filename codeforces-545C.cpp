//https://codeforces.com/problemset/problem/545/C
//C. Woodcutters

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <int> loc(n);
    vector <int> height(n);

    for(int i = 0; i < n; ++i)
        cin >> loc[i] >> height[i];

    int last = INT_MIN;
    int max_count = 0;

    for(int i = 0; i < n - 1; ++i)
        if(loc[i] - height[i] > last){
            ++max_count;
            last = loc[i];
        }
        else if(loc[i] + height[i] < loc[i + 1]){
            ++max_count;
            last = loc[i] + height[i];
        }
        else
            last = loc[i];

    if(loc[n - 1] > last)
        ++max_count;

    cout << max_count << endl;
    return 0;
}

//DYNAMIC PROGRAMMING SOLUTION:
/*
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector <int> loc(n);
    vector <int> height(n);

    for(int i = 0; i < n; ++i)
        cin >> loc[i] >> height[i];

    vector <vector <int> > dp(2, vector <int> (n, 0));
    dp[0][0] = 1;//cut to left or do not cut
    dp[1][0] = 1;//cut to right

    for(int i = 1; i < n; ++i){
        dp[0][i] = dp[0][i - 1];
        dp[1][i] = dp[0][i - 1] + 1;

        if(loc[i] - height[i] > loc[i - 1])
            dp[0][i] = dp[0][i - 1] + 1;
        if(loc[i] - height[i] > loc[i - 1] + height[i - 1])
            dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1);
        if(loc[i] > loc[i - 1] + height[i - 1])
            dp[0][i] = max(dp[0][i], dp[1][i - 1]);

        if(loc[i - 1] + height[i - 1] < loc[i] && loc[i] + height[i] > loc[i - 1] + height[i - 1])
            dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
    }
    
    cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    return 0;
}
*/
