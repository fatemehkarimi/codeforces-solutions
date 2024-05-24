//https://codeforces.com/problemset/problem/687/C
//The Values You Can Make

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector <int> coins(n);
    for(int i = 0; i < n; ++i)
        cin >> coins[i];

    vector < vector <bool> > arr(k + 1, vector <bool> (k + 1, false));
    for(int i = 0; i < k + 1; ++i)
        arr[0][i] = true;

    for(int p = 0; p < n; ++p){
        vector < vector <bool> > tmp_arr = arr;

        for(int j = 0; j < k + 1; ++j)
            if(arr[j][j] && j + coins[p] < k + 1)
                for(int i = 0; i < k + 1; ++i){
                    tmp_arr[i][j + coins[p]] = arr[i][j] | tmp_arr[i][j + coins[p]];

                    if(arr[i][j] && i + coins[p] < k + 1)
                        tmp_arr[i + coins[p]][j + coins[p]] = 1;
                }

        arr = tmp_arr;
    }

    int count = 0;
    for(int i = 0; i < k + 1; ++i)
        if(arr[i][k])
            ++count;

    cout << count << endl;
    for(int i = 0; i < k + 1; ++i)
        if(arr[i][k])
            cout << i << ' ';

    cout << endl;
    
    return 0;
}
