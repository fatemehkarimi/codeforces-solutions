//https://codeforces.com/problemset/problem/22/C
//C. System Administrator

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;
    --v;

    if(m < n - 1){
        cout << -1 << endl;
        return 0;
    }

    vector <vector <int> > Graph(n);
    int isolated = v - 1 >= 0 ? v - 1 : v + 1;

    Graph[v].push_back(isolated);
    Graph[isolated].push_back(v);
    --m;

    for(int i = 0; i < n && m > 0; ++i)
        if(i != isolated)
            for(int j = i + 1; j < n && m > 0; ++j)
                if (j != isolated){
                    Graph[i].push_back(j);
                    Graph[j].push_back(i);
                    --m;
                }

    if(m != 0){
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i)
        for(auto a : Graph[i])
            if(i < a)
                cout << i + 1 << ' ' << a + 1 << endl;
    return 0;
}
