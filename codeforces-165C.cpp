//https://codeforces.com/problemset/problem/165/C
//C. Another Problem on Strings

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int k;
    cin >> k;
    string input;
    cin >> input;

    if(k == 0){//special case
        long long int result = 0;
        long long int consecutive = 0;
        for(int i = 0; i < (int)input.size(); ++i)
            if(input[i] == '0')
                ++consecutive;
            else{
                result += (consecutive * (consecutive + 1) / 2);
                consecutive = 0;
            }
        result += (consecutive * (consecutive + 1)) / 2;
        cout << result << endl;
        return 0;
    }

    vector <long long int> dp(input.size(), 0);
    vector <int> index_1;

    for(int i = 0; i < (int)input.size(); ++i)
        if(input[i] == '0' && i > 0)
            dp[i] = dp[i - 1];
        else if(input[i] == '1'){
            index_1.push_back(i);
 
            if((int)index_1.size() - k < 0)
                continue;

            int left = index_1[index_1.size() - k];
            int factor = 0;
            while(left > 0 && input[--left] == '0')
                ++factor;
            dp[i] = factor + 1;
        }

    long long int result = 0;
    for(int i = 0; i < (int)input.size(); ++i)
        result += dp[i];
    cout << result << endl;
    return 0;
}
