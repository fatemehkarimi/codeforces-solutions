//https://codeforces.com/problemset/problem/1084/C
//C. The Fair Nut and String

#include <iostream>
#include <vector>
#include <string>

#define MODULO 1000000007
using namespace std;

int main(void)
{
    string input;
    cin >> input;

    vector <long long int> dp(input.size());
    int pre_a = -1;
    int last_a = -1;
    for(int i = 0; i < (int)input.size(); ++i)
        if(input[i] == 'a'){
            dp[i]++;
            if(pre_a != -1)
                dp[i] += dp[pre_a];

            if(i > 0 && input[i - 1] == 'b'){
                if(pre_a != -1)
                    dp[i] += dp[pre_a];
            }
            else if(i > 0 && input[i - 1] != 'b'){
                if(last_a != -1)
                    dp[i] += dp[last_a];
            }
            dp[i] %= MODULO;
            last_a = i;
        }
        else if(input[i] == 'b')
            pre_a = last_a;

    if(last_a != -1)
        cout << dp[last_a] << endl;
    else
        cout << 0 << endl;
    return 0;
}
