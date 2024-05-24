//https://codeforces.com/contest/1230/problem/C
//C. Anadi and Domino

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > Graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    if(n <= 6){
        cout << m << endl;
        return 0;
    }

    int result = 0;
    for(int x = 0; x  < 6; ++x){
        int num_node[7];
        int idx = 0;
        for(int i = 0; i < 7; ++i)
            if(x == i)
                continue;
            else
                num_node[i] = idx++;

        for(int i = 0; i < 6; ++i){
            int count = 0;
            num_node[x] = i;
            vector <vector <bool> > matrix(6, vector <bool>(6, false));
            for(int i = 0; i < n; ++i)
                for(auto j : Graph[i]){
                    int x = num_node[i];
                    int y = num_node[j];

                    if(matrix[x][y] == 0 && matrix[y][x] == 0){
                        matrix[x][y] = 1;
                        ++count;
                    }
                }
            result = max(result, count);
        }
    }

    cout << result << endl;
    return 0;
}
