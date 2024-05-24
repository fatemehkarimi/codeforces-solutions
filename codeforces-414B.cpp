//https://codeforces.com/problemset/problem/414/B
//B. Mashmokh and ACM

#include <iostream>
#include <vector>

#define MODULO 1000000007

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector < vector <int> > arr(k + 1, vector <int> (n + 1, 0));
    for(int i = 1; i <= n; ++i)
        arr[1][i] = 1;

    for(int i = 2; i <= k; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = j; k <= n; k += j){
                    arr[i][j] += arr[i - 1][k];
                    arr[i][j] %= MODULO;
            }

    int result = 0;
    for(int i = 1; i <= n; ++i)
        result = (result + arr[k][i]) % MODULO;
    cout << result << endl;
    return 0;
}
