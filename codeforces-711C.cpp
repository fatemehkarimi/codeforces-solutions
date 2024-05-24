//https://codeforces.com/problemset/problem/711/C
// Coloring Trees

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> trees(n);

    for(int i = 0; i < n; ++i){
        cin >> trees[i];
        --trees[i];//colors start from 0 - (m - 1), -1 means no color
    }

    vector < vector <int> > color_needed(n, vector <int> (m));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> color_needed[i][j];

    vector < vector <long long int> > arr(m, vector <long long int> (n + 1, LLONG_MAX));

    for(int p = 1; p <= k; ++p){
        vector < vector <long long int> > tmp_arr(m, vector <long long int> (n + 1, LLONG_MAX));

        if(p == 1){
            if(trees[0] == -1)
                for(int i = 0; i < m; ++i)
                    tmp_arr[i][1] = color_needed[0][i];
            else
                tmp_arr[trees[0]][1] = 0;
        }
        for(int i = p; i < n + 1; ++i){
            if(trees[i - 1] != -1){//tree has color
                if(tmp_arr[trees[i - 1]][i - 1] != LLONG_MAX)
                    tmp_arr[trees[i - 1]][i] = tmp_arr[trees[i - 1]][i - 1];

                for(int q = 0; q < m; ++q)
                    if(q != trees[i - 1] && arr[q][i - 1] != LLONG_MAX)
                        tmp_arr[trees[i - 1]][i] = min(tmp_arr[trees[i - 1]][i], arr[q][i - 1]);
            }
            else{
                for(int j = 0; j < m; ++j){
                    if(tmp_arr[j][i - 1] != LLONG_MAX){
                        tmp_arr[j][i] = min(tmp_arr[j][i], tmp_arr[j][i - 1] + color_needed[i - 1][j]);
                    }

                    for(int q = 0; q < m; ++q)
                        if(q != j && arr[q][i - 1] != LLONG_MAX)
                            tmp_arr[j][i] = min(tmp_arr[j][i], arr[q][i - 1] + color_needed[i - 1][j]);
                }
            }
        }

        arr = tmp_arr;
    }

    long long int minColor = LLONG_MAX;
    for(int i = 0; i < m; ++i)
        minColor = min(minColor, arr[i][n]);

    if(minColor == LLONG_MAX)
        cout << "-1" << endl;
    else
        cout << minColor << endl;

    return 0;
}
