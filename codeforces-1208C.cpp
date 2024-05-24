//https://codeforces.com/contest/1208/problem/C
//C. Magic Grid

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector <vector <int> > arr(n, vector <int>(n, 0));

    int num = 0;
    int row[] = {0, 0, n / 2, n / 2};
    int col[] = {0, n / 2, 0, n / 2};

    for(int i = 0; i < n / 2; ++i)
        for(int j = 0; j < n / 2; ++j){
            for(int k = 0; k < 4; ++k)
                arr[i + row[k]][j + col[k]] = num * 4 + k;
            ++num;
        }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
