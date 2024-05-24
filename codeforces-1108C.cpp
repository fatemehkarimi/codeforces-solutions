//https://codeforces.com/problemset/problem/1108/C
//C. Nice Garland

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int len;
    cin >> len;
    string Garland;
    cin >> Garland;

    char patterns[6][3] = {{'R', 'G', 'B'}, {'R', 'B', 'G'}, {'B', 'R', 'G'},
                           {'B', 'G', 'R'}, {'G', 'R', 'B'}, {'G', 'B', 'R'}};
    int counts[3][3] = {};
    for(int i = 0; i < len; ++i)
        if(Garland[i] == 'R')
            ++counts[i % 3][0];
        else if(Garland[i] == 'G')
            ++counts[i % 3][1];
        else
            ++counts[i % 3][2];

    int minCost = len + 1;
    int index = 0;
    for(int i = 0; i < 6; ++i){
        int cost = 0;
        for(int j = 0; j < 3; ++j)
            if(patterns[i][j] == 'R')
                cost += (counts[j][1] + counts[j][2]);
            else if(patterns[i][j] == 'G')
                cost += (counts[j][0] + counts[j][2]);
            else
                cost += (counts[j][0] + counts[j][1]);
        if(cost <minCost){
            minCost = cost;
            index = i;
        }
    }
    cout << minCost << endl;
    for(int i = 0; i < len; ++i)
        cout << patterns[index][i % 3];
    cout << endl;
    return 0;
}
