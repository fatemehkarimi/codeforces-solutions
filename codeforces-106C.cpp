//https://codeforces.com/problemset/problem/106/C

#include <iostream>
#include <vector>

#include <iomanip>

using namespace std;

int main(void)
{
    int dough, m, d0, c0;
    cin >> dough >> m >> d0 >> c0;

    vector <int> dough_use;
    vector <int> cost;

    for(int i = 0; i < dough / d0; ++i){
        dough_use.push_back(d0);
        cost.push_back(c0);
    }

    for(int i = 1; i <= m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int count = a / b;

        for(int j = 0; j < count; ++j){
            dough_use.push_back(c);
            cost.push_back(d);
        }
    }

    int size = dough_use.size();
    vector < vector <int> > arr(size + 1, vector <int> (dough + 1, 0));

    for(int i = 1; i < size + 1; ++i)
        for(int j = 0; j < dough + 1; ++j)
            if(j - dough_use[i - 1] >= 0)
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - dough_use[i - 1]] + cost[i - 1]);
            else
                arr[i][j] = arr[i - 1][j];

    cout << arr[size][dough] << endl;

    return 0;
}
