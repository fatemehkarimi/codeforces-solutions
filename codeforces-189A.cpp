//http://codeforces.com/problemset/problem/189/A
//A. Cut Ribbon

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, c[3];
    cin >> n >> c[0] >> c[1] >> c[2];

    vector < vector <int> > arr(3, vector <int> (n + 1, -1));

    arr[0][0] = 0;
    for (int i = 0; i <= n; ++i)
        if (i - c[0] >= 0 && arr[0][i - c[0]] >= 0)
            arr[0][i] = arr[0][i - c[0]] + 1;

    for (int i = 1; i < 3; ++i)
        for (int j = 0; j < n + 1; ++j){
            arr[i][j] = max(arr[i - 1][j], arr[i][j]);

            if (j - c[i] >= 0 && arr[i][j - c[i]] >= 0)
                arr[i][j] = max(arr[i][j], arr[i][j - c[i]] + 1);
        }

    cout << arr[2][n] << endl;
    return 0;
}
