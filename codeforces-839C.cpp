//https://codeforces.com/problemset/problem/839/C
//C. Journey

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double DFS(vector <vector <int> > & Tree, vector <bool> & visited, int root, int level, double prob)
{
    visited[root] = true;
    int non_visited = 0;
    for(auto a : Tree[root])
        if(!visited[a])
            ++non_visited;
    if(non_visited == 0)//if root is a leaf
        return level * prob;

    double EV = 0;
    for(auto a : Tree[root])
        if(!visited[a])
            EV += DFS(Tree, visited, a, level + 1, prob * (1.0 / (double)non_visited));
    return EV;
}

int main(void)
{
    int n;
    cin >> n;
    vector < vector <int> > Tree(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    vector <bool> visited(n, false);
    double result = DFS(Tree, visited, 0, 0, 1);
    cout << fixed << setprecision(10) << result << endl;

    return 0;
}

