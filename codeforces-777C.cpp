//DP-CODEFORCES
//https://codeforces.com/problemset/problem/777/C
//C. Alyona and Spreadsheet

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > arr(n, vector <int>(m));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> arr[i][j];

    vector <vector <int> > count(n, vector <int>(m, 0));
    for(int j = 0; j < m; ++j)
        count[0][j] = 1;

    for(int j = 0; j < m; ++j)
        for(int i = 1; i < n; ++i)
            if(arr[i - 1][j] <= arr[i][j])
                count[i][j] = count[i - 1][j] + 1;
            else
                count[i][j] = 1;

    vector <int> max_row(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            max_row[i] = max(max_row[i], count[i][j]);

    int k;
    cin >> k;
    for(int i = 0; i < k; ++i){
        int a, b;
        cin >> a >> b;
        --a, --b;
        if(b - a + 1 <= max_row[b])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
